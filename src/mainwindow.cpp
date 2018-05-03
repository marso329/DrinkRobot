#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
		QMainWindow(parent), ui(new Ui::MainWindow), statemachine(
				new StateMachine()) {
	ui->setupUi(this);
	//QGridLayout* layout = new QGridLayout(ui->login_frame);
	database = new DataBase();
	next_stage = NextStage::none;
	ingrediants_model = new QStandardItemModel(0, 3, this);
	ingrediants_model->setHorizontalHeaderItem(0,
			new QStandardItem(QString("Name")));
	ingrediants_model->setHorizontalHeaderItem(1,
			new QStandardItem(QString("Strength[%]")));
	ingrediants_model->setHorizontalHeaderItem(2,
			new QStandardItem(QString("Price[kr/l]")));

	user_model = new QStandardItemModel(0, 2, this);
	user_model->setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
	user_model->setHorizontalHeaderItem(1, new QStandardItem(QString("Admin")));
	ui->adduser_list->setModel(user_model);
	ui->adduser_list->horizontalHeader()->setSectionResizeMode(
			QHeaderView::Stretch);

	drink_model = new QStandardItemModel(0, 2, this);
	drink_model->setHorizontalHeaderItem(0,
			new QStandardItem(QString("Ingredient")));
	drink_model->setHorizontalHeaderItem(1,
			new QStandardItem(QString("Amount [ml]")));
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

	//connected to this class

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

void MainWindow::user_pressed() {
	QPushButton *button = (QPushButton *) sender();
	std::string user = button->text().toStdString();

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
		statemachine->make_a_drink();
	} else if (correct_pass && next_stage == NextStage::admin
			&& database->isAdmin(user)) {
		statemachine->admin();
		std::cout << "adminpage next" << std::endl;
	} else {
		statemachine->admin_back();
	}

}

void MainWindow::set_add_drink() {

	//setup drink add
	//drink_model->setItem(0, 0, new QStandardItem(name));
	//ComboBoxItemDelegate* cbid = new ComboBoxItemDelegate(ui->adddrink_list);
	//ui->adddrink_list->setItemDelegate(cbid);

	ui->adddrink_list->setItemDelegateForColumn(0, new ComboBoxItemDelegate());
	drink_model->setItem(0, 1, new QStandardItem("456"));
	ui->adddrink_list->openPersistentEditor(drink_model->index(0,0));
	statemachine->set_add_drink();

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
		QString name = QString::fromStdString(std::get<std::string>(user));
		bool admin = std::get<bool>(user);
		QStandardItem* item0 = new QStandardItem(true);
		if (name != "Martin") {
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

	if (topLeft.column() == 1) {
		database->changeAdmin(name, item->checkState() == Qt::Checked);
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

