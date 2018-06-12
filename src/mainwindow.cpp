#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
		QMainWindow(parent), ui(new Ui::MainWindow), statemachine(
				new StateMachine()) {
	ui->setupUi(this);
	srand (time(NULL));
	//QGridLayout* layout = new QGridLayout(ui->login_frame);
	database = new DataBase();
	tempcontroller=new TemperatureController();
	//tempcontroller->disable();
	hardware= new Hardware();
	next_stage = NextStage::none;
	ingrediants_model = new QStandardItemModel(0, 3, this);
	ingrediants_model->setHorizontalHeaderItem(0,
			new QStandardItem(QString("Name")));
	ingrediants_model->setHorizontalHeaderItem(1,
			new QStandardItem(QString("Strength[%]")));
	ingrediants_model->setHorizontalHeaderItem(2,
			new QStandardItem(QString("Price[kr/l]")));

	scoreboard_heighest_model = new QStandardItemModel(0, 2, this);
	scoreboard_heighest_model->setHorizontalHeaderItem(0,
			new QStandardItem(QString("Name")));
	scoreboard_heighest_model->setHorizontalHeaderItem(1,
				new QStandardItem(QString("Promille")));
	ui->scoreboard_heighest_list->setModel(scoreboard_heighest_model);
	ui->scoreboard_heighest_list->horizontalHeader()->setSectionResizeMode(
			QHeaderView::Stretch);
	ui->scoreboard_heighest_list->setItemDelegate(
			new NotEditableDelegate());

	scoreboard_most_model = new QStandardItemModel(0, 2, this);
	scoreboard_most_model->setHorizontalHeaderItem(0,
			new QStandardItem(QString("Name")));
	scoreboard_most_model->setHorizontalHeaderItem(1,
				new QStandardItem(QString("Amount[cl pure alchol]")));
	ui->scoreboard_drinkmost_list->setModel(scoreboard_most_model);
	ui->scoreboard_drinkmost_list->horizontalHeader()->setSectionResizeMode(
			QHeaderView::Stretch);
	ui->scoreboard_drinkmost_list->setItemDelegate(
			new NotEditableDelegate());

	scoreboard_spent_model = new QStandardItemModel(0, 2, this);
	scoreboard_spent_model->setHorizontalHeaderItem(0,
			new QStandardItem(QString("Name")));
	scoreboard_spent_model->setHorizontalHeaderItem(1,
				new QStandardItem(QString("kr")));
	ui->scoreboard_spentmost_list->setModel(scoreboard_spent_model);
	ui->scoreboard_spentmost_list->horizontalHeader()->setSectionResizeMode(
			QHeaderView::Stretch);
	ui->scoreboard_spentmost_list->setItemDelegate(
			new NotEditableDelegate());


	user_model = new QStandardItemModel(0, 4, this);
	user_model->setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
	user_model->setHorizontalHeaderItem(1, new QStandardItem(QString("Admin")));
	user_model->setHorizontalHeaderItem(2, new QStandardItem(QString("Weight[kg]")));
	user_model->setHorizontalHeaderItem(3, new QStandardItem(QString("Male")));
	ui->adduser_list->setModel(user_model);
	ui->adduser_list->horizontalHeader()->setSectionResizeMode(
			QHeaderView::Stretch);
	ui->adduser_list->setItemDelegateForColumn(2,
			new IntRangeDelegate(ui->adduser_list, 0, 200));
	ui->adduser_list->setItemDelegateForColumn(0,
			new NotEditableDelegate());

	drink_model = new QStandardItemModel(0, 2, this);
	drink_model->setHorizontalHeaderItem(0,
			new QStandardItem(QString("Ingredient")));
	drink_model->setHorizontalHeaderItem(1,
			new QStandardItem(QString("Amount [cl]")));
	ui->adddrink_list->setItemDelegateForColumn(1,
			new IntRangeDelegate(ui->adddrink_list, 0, 100));



	ui->adddrink_list->setModel(drink_model);
	ui->adddrink_list->horizontalHeader()->setSectionResizeMode(
			QHeaderView::Stretch);

	//make sure you can edit the drink name
	ui->addingrediant_list->setModel(ingrediants_model);
	ui->addingrediant_list->horizontalHeader()->setSectionResizeMode(
			QHeaderView::Stretch);
	ui->addingrediant_list->setItemDelegateForColumn(0,
			new NotEditableDelegate());
	ui->addingrediant_list->setItemDelegateForColumn(1,
			new IntRangeDelegate(ui->addingrediant_list, 0, 100));
	ui->addingrediant_list->setItemDelegateForColumn(2,
			new IntRangeDelegate(ui->addingrediant_list, 0, 500));

	//connect statemachine to stackedwidget
	this->ui->stackedWidget->setCurrentIndex(0);
	this->set_add_ingrediant();
	connect(this->statemachine, SIGNAL(changeWidget(int)), ui->stackedWidget,
			SLOT(setCurrentIndex(int)));
	connect(this->statemachine, SIGNAL(set_add_ingrediant()), this,
			SLOT(set_add_ingrediant()));
	connect(ui->addingrediant_ok, SIGNAL(clicked()), this,
			SLOT(add_ingrediant_ok()));
	connect(ingrediants_model,
			SIGNAL(
					dataChanged(const QModelIndex &, const QModelIndex &, const QVector<int>&)),
			this,
			SLOT(
					ingrediantDataChanged(const QModelIndex &, const QModelIndex &, const QVector<int> & )));

	connect(user_model,
			SIGNAL(
					dataChanged(const QModelIndex &, const QModelIndex &, const QVector<int>&)),
			this,
			SLOT(
					userDataChanged(const QModelIndex &, const QModelIndex &, const QVector<int> & )));

	connect(ui->addingrediant_remove, SIGNAL(clicked()), this,
			SLOT(remove_ingrediant()));

	//connected to statemachine
	connect(ui->graphicsView, SIGNAL(clicked()), this->statemachine,
			SLOT(startpage_pressed()));
	connect(ui->make_a_drink, SIGNAL(clicked()), this, SLOT(make_drink()));
	connect(ui->admin, SIGNAL(clicked()), this, SLOT(admin()));
	connect(ui->admin_back, SIGNAL(clicked()), this->statemachine,
			SLOT(admin_back()));
	//connect(ui->login_cancel, SIGNAL(clicked()), this->statemachine,
	//		SLOT(login_cancel()));
	//connect(ui->login_ok, SIGNAL(clicked()), this->statemachine,
	//		SLOT(login_ok()));
	connect(ui->drink_back, SIGNAL(clicked()), this->statemachine,
			SLOT(drink_back()));

	connect(ui->add_user, SIGNAL(clicked()), this, SLOT(set_add_user()));
	connect(ui->adduser_ok, SIGNAL(clicked()), this, SLOT(add_user()));
	connect(ui->adduser_back, SIGNAL(clicked()), this->statemachine,
			SLOT(add_user_back()));
	connect(ui->adduser_remove, SIGNAL(clicked()), this, SLOT(remove_user()));

	connect(ui->add_ingredient, SIGNAL(clicked()), this->statemachine,
			SLOT(add_ingrediant()));
	connect(ui->addingrediant_back, SIGNAL(clicked()), this->statemachine,
			SLOT(add_ingrediant_back()));
	connect(ui->set_levels, SIGNAL(clicked()), this, SLOT(set_levels()));
	connect(ui->setlevel_back, SIGNAL(clicked()), this,
			SLOT(set_levels_done()));

	connect(ui->add_drink, SIGNAL(clicked()), this, SLOT(set_add_drink()));
	connect(ui->adddrink_back, SIGNAL(clicked()), this->statemachine,
			SLOT(add_drink_back()));

	connect(ui->adddrink_adddrink, SIGNAL(clicked()), this,
			SLOT(add_drink()));

	//connect(ui->adddrink_drinkselect, SIGNAL(currentTextChanged(const QString &)), this,
		//	SLOT(drink_changed(const Qstring&)));

	connect(ui->adddrink_drinkselect, &QComboBox::currentTextChanged, this, &MainWindow::drink_changed);

	connect(ui->adddrink_addingredient,&QPushButton::clicked,this,&MainWindow::add_ingredient_to_drink);

	connect (drink_model,&QStandardItemModel::dataChanged,this,&MainWindow::drinkDataChanged);

	connect(ui->adddrink_select_icon,&QPushButton::clicked,this,&MainWindow::select_icon);
	//connected to this class
	load_icons();
	load_gifs();

	connect(ui->admin_temp, SIGNAL(clicked()), this->statemachine,
			SLOT(set_temp()));

	connect(ui->settemp_back, SIGNAL(clicked()), this->statemachine,
				SLOT(set_temp_back()));

	connect(tempcontroller, SIGNAL(updated()), this,
				SLOT(update_temperatures()));

	connect(ui->settemp_tank0_set,SIGNAL(valueChanged(int)),this,SLOT(set_temp_changed(int)));
	connect(ui->settemp_tank1_set,SIGNAL(valueChanged(int)),this,SLOT(set_temp_changed(int)));
	connect(ui->settemp_tank2_set,SIGNAL(valueChanged(int)),this,SLOT(set_temp_changed(int)));
	connect(ui->settemp_tank3_set,SIGNAL(valueChanged(int)),this,SLOT(set_temp_changed(int)));
	connect(ui->settemp_tank4_set,SIGNAL(valueChanged(int)),this,SLOT(set_temp_changed(int)));
	connect(ui->settemp_tank5_set,SIGNAL(valueChanged(int)),this,SLOT(set_temp_changed(int)));
	connect(ui->settemp_tank6_set,SIGNAL(valueChanged(int)),this,SLOT(set_temp_changed(int)));
	connect(ui->settemp_tank7_set,SIGNAL(valueChanged(int)),this,SLOT(set_temp_changed(int)));
	connect(ui->settemp_tank8_set,SIGNAL(valueChanged(int)),this,SLOT(set_temp_changed(int)));
	connect(ui->settemp_tank9_set,SIGNAL(valueChanged(int)),this,SLOT(set_temp_changed(int)));

	connect(ui->scoreboard, SIGNAL(clicked()), this,
				SLOT(setup_scoreboard()));
	connect(ui->scoreboard_back, SIGNAL(clicked()), this->statemachine,
				SLOT(scoreboard_back()));

	connect(hardware, SIGNAL(updated()), this,
				SLOT(update_loading()));
	//so everything is set to max at start
	set_temp_changed(0);
}


void MainWindow::add_user() {
	std::string name = ui->name_input->text().toStdString();
	ui->name_input->clear();
	std::string pass = ui->pass_input->text().toStdString();
	ui->pass_input->clear();
	bool admin = ui->admin_input->isChecked();
	database->addUser(name, pass, admin);
	this->set_add_user();

}

MainWindow::~MainWindow() {
	delete database;
	delete statemachine;

}

void MainWindow::update_temperatures(){
	std::vector<int> temp= tempcontroller->get_temperaturs();
	ui->settemp_tank0_actual->setValue(temp[0]);
	ui->settemp_tank1_actual->setValue(temp[1]);
	ui->settemp_tank2_actual->setValue(temp[2]);
	ui->settemp_tank3_actual->setValue(temp[3]);
	ui->settemp_tank4_actual->setValue(temp[4]);
	ui->settemp_tank5_actual->setValue(temp[5]);
	ui->settemp_tank6_actual->setValue(temp[6]);
	ui->settemp_tank7_actual->setValue(temp[7]);
	ui->settemp_tank8_actual->setValue(temp[8]);
	ui->settemp_tank9_actual->setValue(temp[9]);
}

void MainWindow::set_temp_changed(int value){
	(void)value;
	database->setTemp(0,ui->settemp_tank0_set->value());
	database->setTemp(1,ui->settemp_tank1_set->value());
	database->setTemp(2,ui->settemp_tank2_set->value());
	database->setTemp(3,ui->settemp_tank3_set->value());
	database->setTemp(4,ui->settemp_tank4_set->value());
	database->setTemp(5,ui->settemp_tank5_set->value());
	database->setTemp(6,ui->settemp_tank6_set->value());
	database->setTemp(7,ui->settemp_tank7_set->value());
	database->setTemp(8,ui->settemp_tank8_set->value());
	database->setTemp(9,ui->settemp_tank9_set->value());
	tempcontroller->set_temperature(0,ui->settemp_tank0_set->value());
	tempcontroller->set_temperature(1,ui->settemp_tank1_set->value());
	tempcontroller->set_temperature(2,ui->settemp_tank2_set->value());
	tempcontroller->set_temperature(3,ui->settemp_tank3_set->value());
	tempcontroller->set_temperature(4,ui->settemp_tank4_set->value());
	tempcontroller->set_temperature(5,ui->settemp_tank5_set->value());
	tempcontroller->set_temperature(6,ui->settemp_tank6_set->value());
	tempcontroller->set_temperature(7,ui->settemp_tank7_set->value());
	tempcontroller->set_temperature(8,ui->settemp_tank8_set->value());
	tempcontroller->set_temperature(9,ui->settemp_tank9_set->value());
}

void MainWindow::select_icon(){
	Ui_iconselector_dialog* icon_selector = new Ui_iconselector_dialog();
	QDialog* temp = new QDialog();
	icon_selector->setupUi(temp);
	QObject::connect(this, SIGNAL(closeDialog(int)), temp, SLOT(done(int)));
	//icon_selector->
	QGridLayout* layout = new QGridLayout(icon_selector->frame);
	int col = 0;
	int row = 0;
	for (auto it =icons.begin();it!=icons.end();it++){
		QToolButton* button = new QToolButton();
		button->setText(QString::fromStdString(it->first));
		button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
		button->setIcon(it->second);
		//button->setIconSize(pixmap.rect().size());
		button->setFixedSize(200, 200);
		layout->addWidget(button, row, col);
		QSize size(200,180);
		button->setIconSize(size);
		connect(button, SIGNAL(clicked()), this, SLOT(select_icon_callback()));
		col++;
		if (col == 2) {
			col = 0;
			row++;
		}

	}
	icon_selector->scrollArea->setWidgetResizable(true);
	//icon_selector->frame->setFixedWidth(icon_selector->scrollArea->width());
	temp->exec();

}
void MainWindow::select_icon_callback(){
	QPushButton *button = (QPushButton *) sender();
	std::string icon = button->text().toStdString();
	std::string drink=ui->adddrink_drinkselect->currentText().toStdString();
	database->setIcon(drink,icon);
	Q_EMIT closeDialog(1);
}

//load all icons in resources that has a filename of three digits.png
void MainWindow::load_icons(){
	QDirIterator it(":images/", QDirIterator::Subdirectories);
	QRegExp re("^(\\d{3}).png$");
	while (it.hasNext()) {
		if(re.exactMatch(it.fileName())){
			QPixmap pixmap(it.fileInfo().bundleName());
			QIcon ButtonIcon(pixmap);
			icons[it.fileInfo().baseName().toStdString()]=ButtonIcon;
		}
	    qDebug() << it.next();
	}
}
void MainWindow::load_gifs(){
	QDirIterator it(":images/", QDirIterator::Subdirectories);
	QRegExp re("^.*gif$");
	while (it.hasNext()) {
		std::cout<<it.fileName().toStdString()<<std::endl;
		if(re.exactMatch(it.fileName())){
			QMovie* movie = new QMovie(it.fileInfo().bundleName());
			if (movie->isValid())
			{
				std::cout<<"valid"<<std::endl;
				gifs.push_back(movie);
			}


		}
		qDebug() << it.next();
		}
}


void MainWindow::setup_login() {
	QLayoutItem* item;
	if (ui->login_frame->layout() != NULL) {
		while ((item = ui->login_frame->layout()->takeAt(0)) != NULL) {
			delete item->widget();
			delete item;
		}
		delete ui->login_frame->layout();
	}
	//ui->loginpage->la
	QGridLayout* layout = new QGridLayout(ui->login_frame);
	std::vector<std::tuple<std::string, bool>> users = database->getUsers();
	int col = 0;
	int row = 0;
	for (auto it = users.begin(); it != users.end(); it++) {
		QPushButton* button = new QPushButton(
				QString::fromStdString(std::get<std::string>(*it)));
		button->setFixedSize(200, 200);
		layout->addWidget(button, row, col);
		connect(button, SIGNAL(clicked()), this, SLOT(user_pressed()));
		col++;
		if (col == 2) {
			col = 0;
			row++;
		}
	}
}

void MainWindow::setup_make_drink(){
	std::vector<std::string> drinks=database->getDrinks();
	QLayoutItem* item;
	//clear previous drinks
	if (ui->drinkpage_frame->layout() != NULL) {
		while ((item = ui->drinkpage_frame->layout()->takeAt(0)) != NULL) {
			delete item->widget();
			delete item;
		}
		delete ui->drinkpage_frame->layout();
	}
	QGridLayout* layout = new QGridLayout(ui->drinkpage_frame);
	//ui->drinkpage_scrollArea->setStyleSheet("background-color:transparent;");
	int col = 0;
	int row = 0;
	for (auto it =drinks.begin();it!=drinks.end();it++){
		QToolButton* button = new QToolButton();
		button->setText(QString::fromStdString(*it));
		button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
		button->setIcon(icons[database->getIcon(*it)]);
		button->setFixedSize(200, 200);
		button->setEnabled(database->drinkFeasible(*it));
		//button->setStyleSheet("background-color:transparent;");
		layout->addWidget(button, row, col);
		QSize size(200,170);
		button->setIconSize(size);
		connect(button, SIGNAL(clicked()), this, SLOT(drink_selected()));
		col++;
		if (col == 2) {
			col = 0;
			row++;
		}

	}
	ui->drinkpage_scrollArea->setWidgetResizable(true);



}
void MainWindow::update_loading(){
	std::cout<<"update called"<<std::endl;
	if (tanksAmount.size()==0){
		std::cout<<"closed winow"<<std::endl;
		Q_EMIT(closeLoading(1));
		return;
	}
	std::tuple<int,int> currenTankAmount=tanksAmount[0];
	tanksAmount.erase(tanksAmount.begin());
	int tank=std::get<0>(currenTankAmount);
	int amount =std::get<1>(currenTankAmount);
	std::ostringstream infotext;
	infotext<<"Pouring "<<amount<<" cl of"<<database->getIngredientFromTank(tank);
	loading->info_label->setText(QString::fromStdString(infotext.str()));
	 hardware->pour(tank,amount);
}

void MainWindow::drink_selected(){
	QPushButton *button = (QPushButton *) sender();
	std::string drink = button->text().toStdString();
	tanksAmount=database->getTanksAndAmountForDrink(drink);
	loading = new Ui_Loading();
	QDialog* temp = new QDialog();
	QObject::connect(this, SIGNAL(closeLoading(int)), temp, SLOT(done(int)));
	loading->setupUi(temp);
	temp->setModal(true);
	float promille=database->getPromille(current_user);
	float amount=database->getStrength(drink);
	database->addAmountToUser(current_user,amount);
	database->addCostToUser(current_user,database->getCost(drink));
	float new_promille=database->getPromille(current_user);
	std::ostringstream promilletext;
	promilletext<<"Hello "<<current_user<<" your promille level before this drink was \n"<<promille<<" and after this drink it will be "<<new_promille;
	loading->promille_label->setText(QString::fromStdString(promilletext.str()));
	int random=rand()%gifs.size();
	QMovie* movie=gifs[random];
	loading->gif_label->setMovie(movie);
	 loading->gif_label->show();
	    movie->start();
	    update_loading();
	    temp->exec();
	    delete loading;
	    delete temp;



}

void MainWindow::user_pressed() {
	QPushButton *button = (QPushButton *) sender();
	std::string user = button->text().toStdString();
	current_user=user;

	Ui_passwordDialog* password = new Ui_passwordDialog();
	QDialog* temp = new QDialog();
	password->setupUi(temp);
	QObject::connect(password->ok, SIGNAL(pressed()), this,
			SLOT(passwordFunc()));
	QObject::connect(this, SIGNAL(closeDialog(int)), temp, SLOT(done(int)));
	temp->exec();
	std::string pass = password->password->text().toStdString();
	delete password;
	delete temp;
	bool correct_pass = database->checkUser(user, pass);
	if (correct_pass && next_stage == NextStage::make_a_drink) {
		setup_make_drink();
		statemachine->make_a_drink();
	} else if (correct_pass && next_stage == NextStage::admin
			&& database->isAdmin(user)) {
		statemachine->admin();
	} else {
		statemachine->admin_back();
	}

}

void MainWindow::add_ingredient_to_drink(){
	//QList<QStandardItem *> temp;
	//drink_model->appendRow(temp);
	int rows= drink_model->rowCount();
	drink_model->setItem(rows, 1, new QStandardItem("0"));
	ui->adddrink_list->openPersistentEditor(drink_model->index(rows,0));

}


void MainWindow::drinkDataChanged(const QModelIndex &topLeft,
		const QModelIndex &bottomRight, const QVector<int> &roles) {
	if(settings_up_drinks){
		return;
	}
	(void) bottomRight;
	(void) roles;
	(void) topLeft;

	std::string drink=ui->adddrink_drinkselect->currentText().toStdString();
	database->clearDrinkIngredients(drink);
	for(int i=0;i<drink_model->rowCount();i++){
		QModelIndex index = drink_model->index(i, 0, QModelIndex());
		std::string ingredient = drink_model->data(index).toString().toStdString();
		index = drink_model->index(i, 1, QModelIndex());
		std::string amount = drink_model->data(index).toString().toStdString();
		std::cout<<"amount "<<amount<<std::endl;
		int amountint=0;
		try{
		amountint=std::stoi(amount);
		}
		catch(std::invalid_argument& e){
		}
		std::cout<<"amountint "<<amountint<<std::endl;
		database->addIngredientToDrink(drink,ingredient,amountint);
	}
}

void MainWindow::add_drink(){
	std::string name=ui->adddrink_drinkname->text().toStdString();
	ui->adddrink_drinkname->clear();
	if (name.find_first_not_of(" \t") == std::string::npos) {
		return;
	}
	database->addDrink(name);
	set_add_drink();
	int index= ui->adddrink_drinkselect->findText(QString::fromStdString(name));
	if(index!=-1){
		ui->adddrink_drinkselect->setCurrentIndex(index);
	}
}

void MainWindow::set_add_drink() {
	std::vector<std::string> drinks=database->getDrinks();
	ui->adddrink_drinkselect->clear();
	for(auto it =drinks.begin();it!=drinks.end();it++){
		ui->adddrink_drinkselect->addItem(QString::fromStdString(*it));
	}

	//ui->adddrink_list->setItemDelegateForColumn(0, new ComboBoxItemDelegate());
	//drink_model->setItem(0, 1, new QStandardItem("456"));
	//ui->adddrink_list->openPersistentEditor(drink_model->index(0,0));
	statemachine->set_add_drink();
}

//when the drink selector in the add drink page changes
void MainWindow::drink_changed(const QString &text){
	settings_up_drinks=true;
	std::string name=text.toStdString();
	std::vector<std::tuple<std::string, int>> ingredients=database->getIngredientsInDrink(name);

	std::vector<std::string> allingredients=database->getIngrediantsName();
	drink_model->clear();
	drink_model->setHorizontalHeaderItem(0,
			new QStandardItem(QString("Ingredient")));
	drink_model->setHorizontalHeaderItem(1,
			new QStandardItem(QString("Amount [cl]")));
	ui->adddrink_list->setItemDelegateForColumn(0, new ComboBoxItemDelegate(allingredients));
	int ind=0;
	for(auto it=ingredients.begin();it!=ingredients.end();it++){
		std::tuple<std::string, int> ingrediant = (*it);
		std::string ingredient_name =
				std::get<std::string>(ingrediant);
		int amount = std::get<1>(ingrediant);
		std::ostringstream temp;
		temp<<amount;
		//add amount
		drink_model->setItem(ind, 1, new QStandardItem(QString::fromStdString(temp.str())));
		QModelIndex index = drink_model->index(ind, 0, QModelIndex());
		QStandardItem* item = drink_model->itemFromIndex(index);
		item->setText(QString::fromStdString(ingredient_name));
		ui->adddrink_list->openPersistentEditor(drink_model->index(ind,0));
		ind++;
	}
	settings_up_drinks=false;

}

void MainWindow::passwordFunc() {
	Q_EMIT closeDialog(1);
}

void MainWindow::make_drink() {
	next_stage = NextStage::make_a_drink;
	setup_login();
	statemachine->login();

}

void MainWindow::admin() {
	next_stage = NextStage::admin;
	setup_login();
	statemachine->login();

}
void MainWindow::setup_scoreboard(){
	scoreboard_heighest_model->removeRows(0, scoreboard_heighest_model->rowCount());
	scoreboard_most_model->removeRows(0, scoreboard_most_model->rowCount());
	std::vector<std::tuple<std::string,bool>> users= database->getUsers();
	int counter = 0;
	for(auto it  =users.begin();it!=users.end();it++){
		std::string name =std::get<std::string>(*it);

		scoreboard_heighest_model->setItem(counter, 0, new QStandardItem(QString::fromStdString(name)));
		QStandardItem* item0=new QStandardItem(QString::number(database->getPromille(name)));
		item0->setData(database->getPromille(name));
		scoreboard_heighest_model->setItem(counter, 1, item0);

		scoreboard_most_model->setItem(counter, 0, new QStandardItem(QString::fromStdString(name)));
		QStandardItem* item1 =new QStandardItem(QString::number(database->getTotalAmount(name)));
		item1->setData(database->getTotalAmount(name));
		scoreboard_most_model->setItem(counter, 1, item1);

		scoreboard_spent_model->setItem(counter, 0, new QStandardItem(QString::fromStdString(name)));
		QStandardItem* item2 =new QStandardItem(QString::number(database->getUserSpent(name)));
		item2->setData(database->getUserSpent(name));
		scoreboard_spent_model->setItem(counter, 1, item2);

		scoreboard_heighest_model->sort(1, Qt::AscendingOrder);
		scoreboard_most_model->sort(1, Qt::AscendingOrder);
		scoreboard_spent_model->sort(1, Qt::AscendingOrder);
	}

	statemachine->scoreboard();
}

void MainWindow::set_add_ingrediant() {
	settings_up_ingredients = true;
	std::vector<std::tuple<std::string, int, int>> ingredients =
			database->getIngrediants();
	//clear previous data
	ingrediants_model->removeRows(0, ingrediants_model->rowCount());
	int counter = 0;
	for (auto it = ingredients.begin(); it != ingredients.end(); it++) {
		std::tuple<std::string, int, int> ingrediant = (*it);
		QString name = QString::fromStdString(
				std::get<std::string>(ingrediant));
		int strength = std::get<1>(ingrediant);
		int price = std::get<2>(ingrediant);
		QString strength_str = QString::fromStdString(std::to_string(strength));
		QString price_str = QString::fromStdString(std::to_string(price));
		ingrediants_model->setItem(counter, 0, new QStandardItem(name));
		ingrediants_model->setItem(counter, 1, new QStandardItem(strength_str));
		ingrediants_model->setItem(counter, 2, new QStandardItem(price_str));
		counter++;

	}
	ingrediants_model->sort(0, Qt::AscendingOrder);
	settings_up_ingredients = false;
}

void MainWindow::set_add_user() {
	settings_up_users = true;
	std::vector<std::tuple<std::string, bool>> users = database->getUsers();
	//clear previous data
	user_model->removeRows(0, user_model->rowCount());
	int counter = 0;
	for (auto it = users.begin(); it != users.end(); it++) {
		std::tuple<std::string, bool> user = (*it);
		std::string name_std=std::get<std::string>(user);
		QString name = QString::fromStdString(std::get<std::string>(user));
		bool admin = std::get<bool>(user);
		QStandardItem* item0 = new QStandardItem(true);
		if (name != "martin") {
			item0->setCheckable(true);
		} else {
			item0->setCheckable(false);
		}
		if (admin) {
			item0->setCheckState(Qt::Checked);
		} else {
			item0->setCheckState(Qt::Unchecked);
		}
		item0->setText("Admin");
		item0->setEditable(false);
		user_model->setItem(counter, 0, new QStandardItem(name));
		user_model->setItem(counter, 1, item0);
		//newly added
		QString weight_str = QString::fromStdString(std::to_string(database->getWeight(name_std)));
		QStandardItem* item1 = new QStandardItem(weight_str);
		QStandardItem* item2 = new QStandardItem(true);
		item2->setCheckable(true);
		if (database->getMale(name_std)) {
			item2->setCheckState(Qt::Checked);
		} else {
			item2->setCheckState(Qt::Unchecked);
		}
		item2->setText("Male");
		item2->setEditable(false);

		user_model->setItem(counter, 2, item1);
		user_model->setItem(counter, 3, item2);

		counter++;

	}
	user_model->sort(0, Qt::AscendingOrder);
	settings_up_users = false;
	statemachine->add_user();
}

void MainWindow::add_ingrediant_ok() {
	std::string name = ui->addingrediant_name->text().toStdString();
	if (name.find_first_not_of(" \t") == std::string::npos) {
		ui->addingrediant_name->clear();
		ui->addingrediant_strength->clear();
		ui->addingrediant_price->clear();
		return;
	}
	ui->addingrediant_name->clear();

	int strength = ui->addingrediant_strength->value();
	ui->addingrediant_strength->clear();
	int price = ui->addingrediant_price->value();
	ui->addingrediant_price->clear();
	database->addIngrediant(name, strength, price);
	this->set_add_ingrediant();

}

void MainWindow::userDataChanged(const QModelIndex &topLeft,
		const QModelIndex &bottomRight, const QVector<int> &roles) {
	(void) bottomRight;
	(void) roles;
	//name
	if (topLeft.column() == 0) {
		return;
	}
	if (settings_up_users) {
		return;
	}
	QModelIndex index = user_model->index(topLeft.row(), 0, QModelIndex());
	std::string name = user_model->data(index).toString().toStdString();

	index = user_model->index(topLeft.row(), 1, QModelIndex());
	QStandardItem* item = user_model->itemFromIndex(index);

	index = user_model->index(topLeft.row(), 3, QModelIndex());
	QStandardItem* item0 = user_model->itemFromIndex(index);

	if (topLeft.column() == 1) {
		database->changeAdmin(name, item->checkState() == Qt::Checked);
	}
	if (topLeft.column() == 2) {
		database->setWeight(name, topLeft.data().toInt());
	}
	if (topLeft.column() == 3) {
			database->setMale(name, item0->checkState() == Qt::Checked);
		}


}

void MainWindow::ingrediantDataChanged(const QModelIndex &topLeft,
		const QModelIndex &bottomRight, const QVector<int> &roles) {
	(void) bottomRight;
	(void) roles;
	//name
	if (topLeft.column() == 0) {
		return;
	}
	if (settings_up_ingredients) {
		return;
	}
	QModelIndex index = ingrediants_model->index(topLeft.row(), 0,
			QModelIndex());
	std::string name = ingrediants_model->data(index).toString().toStdString();
	if (topLeft.column() == 1) {
		database->changeIngrediant(name, topLeft.data().toInt(), -1);
	}
	if (topLeft.column() == 2) {
		database->changeIngrediant(name, -1, topLeft.data().toInt());
	}

}

void MainWindow::remove_ingrediant() {
	QItemSelectionModel *select = ui->addingrediant_list->selectionModel();
	if (select->hasSelection()) {
		QModelIndexList list = select->selectedRows();
		for (auto it = list.begin(); it != list.end(); it++) {
			int row = it->row();
			QModelIndex index = ingrediants_model->index(row, 0, QModelIndex());
			std::string name =
					ingrediants_model->data(index).toString().toStdString();
			database->removeIngrediant(name);
			ingrediants_model->removeRow(row, QModelIndex());

		}
	}
}

void MainWindow::remove_user() {
	QItemSelectionModel *select = ui->adduser_list->selectionModel();
	if (select->hasSelection()) {
		QModelIndexList list = select->selectedRows();
		for (auto it = list.begin(); it != list.end(); it++) {
			int row = it->row();
			QModelIndex index = user_model->index(row, 0, QModelIndex());
			std::string name = user_model->data(index).toString().toStdString();
			if (name == "Martin") {
				return;
			}
			database->removeUser(name);
			user_model->removeRow(row, QModelIndex());

		}
	}
	this->set_add_user();
}

void MainWindow::set_levels() {
	std::vector<std::string> ingredients = database->getIngrediantsName();
	QStandardItemModel* pModel = new QStandardItemModel();
	QStandardItem* dummy = new QStandardItem("Choose ingredient");
	dummy->setSelectable(false);

	pModel->appendRow(dummy);

	for (auto it = ingredients.begin(); it != ingredients.end(); it++) {
		pModel->appendRow(new QStandardItem(QString::fromStdString(*it)));
	}
	std::tuple<std::string, int> temp = database->getLevel(0);
	ui->setlevelindicator0->setValue(std::get<int>(temp));
	ui->setlevellist0->setModel(pModel);
	ui->setlevellist0->setEditable(false);
	ui->setlevellist0->setCurrentText(
			QString::fromStdString(std::get<std::string>(temp)));

	temp = database->getLevel(1);
	ui->setlevelindicator1->setValue(std::get<int>(temp));
	ui->setlevellist1->setModel(pModel);
	ui->setlevellist1->setEditable(false);
	ui->setlevellist1->setCurrentText(
			QString::fromStdString(std::get<std::string>(temp)));

	temp = database->getLevel(2);
	ui->setlevelindicator2->setValue(std::get<int>(temp));
	ui->setlevellist2->setModel(pModel);
	ui->setlevellist2->setEditable(false);
	ui->setlevellist2->setCurrentText(
			QString::fromStdString(std::get<std::string>(temp)));

	temp = database->getLevel(3);
	ui->setlevelindicator3->setValue(std::get<int>(temp));
	ui->setlevellist3->setModel(pModel);
	ui->setlevellist3->setEditable(false);
	ui->setlevellist3->setCurrentText(
			QString::fromStdString(std::get<std::string>(temp)));

	temp = database->getLevel(4);
	ui->setlevelindicator4->setValue(std::get<int>(temp));
	ui->setlevellist4->setModel(pModel);
	ui->setlevellist4->setEditable(false);
	ui->setlevellist4->setCurrentText(
			QString::fromStdString(std::get<std::string>(temp)));

	temp = database->getLevel(5);
	ui->setlevelindicator5->setValue(std::get<int>(temp));
	ui->setlevellist5->setModel(pModel);
	ui->setlevellist5->setEditable(false);
	ui->setlevellist5->setCurrentText(
			QString::fromStdString(std::get<std::string>(temp)));

	temp = database->getLevel(6);
	ui->setlevelindicator6->setValue(std::get<int>(temp));
	ui->setlevellist6->setModel(pModel);
	ui->setlevellist6->setEditable(false);
	ui->setlevellist6->setCurrentText(
			QString::fromStdString(std::get<std::string>(temp)));

	temp = database->getLevel(7);
	ui->setlevelindicator7->setValue(std::get<int>(temp));
	ui->setlevellist7->setModel(pModel);
	ui->setlevellist7->setEditable(false);
	ui->setlevellist7->setCurrentText(
			QString::fromStdString(std::get<std::string>(temp)));

	temp = database->getLevel(8);
	ui->setlevelindicator8->setValue(std::get<int>(temp));
	ui->setlevellist8->setModel(pModel);
	ui->setlevellist8->setEditable(false);
	ui->setlevellist8->setCurrentText(
			QString::fromStdString(std::get<std::string>(temp)));

	temp = database->getLevel(9);
	ui->setlevelindicator9->setValue(std::get<int>(temp));
	ui->setlevellist9->setModel(pModel);
	ui->setlevellist9->setEditable(false);
	ui->setlevellist9->setCurrentText(
			QString::fromStdString(std::get<std::string>(temp)));

	statemachine->set_levels();
}

void MainWindow::set_levels_done() {
	if (ui->setlevellist0->currentIndex() > 0) {
		database->setlevel(0, ui->setlevellist0->currentText().toStdString(),
				ui->setlevelindicator0->value());
	} else {
		database->setlevel(0, "", 0);
	}

	if (ui->setlevellist1->currentIndex() > 0) {
		database->setlevel(1, ui->setlevellist1->currentText().toStdString(),
				ui->setlevelindicator1->value());
	} else {
		database->setlevel(1, "", 0);
	}

	if (ui->setlevellist2->currentIndex() > 0) {
		database->setlevel(2, ui->setlevellist2->currentText().toStdString(),
				ui->setlevelindicator2->value());
	} else {
		database->setlevel(2, "", 0);
	}

	if (ui->setlevellist3->currentIndex() > 0) {
		database->setlevel(3, ui->setlevellist3->currentText().toStdString(),
				ui->setlevelindicator3->value());
	} else {
		database->setlevel(3, "", 0);
	}

	if (ui->setlevellist4->currentIndex() > 0) {
		database->setlevel(4, ui->setlevellist4->currentText().toStdString(),
				ui->setlevelindicator4->value());
	} else {
		database->setlevel(4, "", 0);
	}

	if (ui->setlevellist5->currentIndex() > 0) {
		database->setlevel(5, ui->setlevellist5->currentText().toStdString(),
				ui->setlevelindicator5->value());
	} else {
		database->setlevel(5, "", 0);
	}

	if (ui->setlevellist6->currentIndex() > 0) {
		database->setlevel(6, ui->setlevellist6->currentText().toStdString(),
				ui->setlevelindicator6->value());
	} else {
		database->setlevel(6, "", 0);
	}

	if (ui->setlevellist7->currentIndex() > 0) {
		database->setlevel(7, ui->setlevellist7->currentText().toStdString(),
				ui->setlevelindicator7->value());
	} else {
		database->setlevel(7, "", 0);
	}

	if (ui->setlevellist8->currentIndex() > 0) {
		database->setlevel(8, ui->setlevellist8->currentText().toStdString(),
				ui->setlevelindicator8->value());
	} else {
		database->setlevel(8, "", 0);
	}

	if (ui->setlevellist9->currentIndex() > 0) {
		database->setlevel(9, ui->setlevellist9->currentText().toStdString(),
				ui->setlevelindicator9->value());
	} else {
		database->setlevel(9, "", 0);
	}

	statemachine->set_levels_back();
}

