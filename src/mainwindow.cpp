#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
		QMainWindow(parent), ui(new Ui::MainWindow), statemachine(
				new StateMachine()) {
	ui->setupUi(this);
	database = new DataBase();
	ingrediants_model = new QStandardItemModel(0, 3, this);
	ingrediants_model->setHorizontalHeaderItem(0,
			new QStandardItem(QString("Ingrediant")));
	ingrediants_model->setHorizontalHeaderItem(1,
			new QStandardItem(QString("Strength[%]")));
	ingrediants_model->setHorizontalHeaderItem(2,
			new QStandardItem(QString("Price[kr/l]")));
	//make sure you can edit the drink name
	ui->addingrediant_list->setModel(ingrediants_model);
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
	connect(ui->addingrediant_remove, SIGNAL(clicked()), this,
			SLOT(remove_ingrediant()));

	//connected to statemachine
	connect(ui->graphicsView, SIGNAL(clicked()), this->statemachine,
			SLOT(startpage_pressed()));
	connect(ui->make_a_drink, SIGNAL(clicked()), this->statemachine,
			SLOT(make_a_drink()));
	connect(ui->admin, SIGNAL(clicked()), this->statemachine, SLOT(admin()));
	connect(ui->admin_back, SIGNAL(clicked()), this->statemachine,
			SLOT(admin_back()));
	connect(ui->login_cancel, SIGNAL(clicked()), this->statemachine,
			SLOT(login_cancel()));
	connect(ui->login_ok, SIGNAL(clicked()), this->statemachine,
			SLOT(login_ok()));
	connect(ui->drink_back, SIGNAL(clicked()), this->statemachine,
			SLOT(drink_back()));
	connect(ui->add_user, SIGNAL(clicked()), this->statemachine,
			SLOT(add_user()));
	connect(ui->adduser_ok, SIGNAL(clicked()), this, SLOT(add_user()));
	connect(ui->add_ingredient, SIGNAL(clicked()), this->statemachine,
			SLOT(add_ingrediant()));
	connect(ui->addingrediant_back, SIGNAL(clicked()), this->statemachine,
			SLOT(add_ingrediant_back()));

	//connected to this class

}
void MainWindow::add_user() {
	std::string name = ui->name_input->text().toStdString();
	std::string pass = ui->pass_input->text().toStdString();
	bool admin = ui->admin_input->isChecked();
	database->addUser(name, pass, admin);
	statemachine->add_user_ok();

}

MainWindow::~MainWindow() {
	delete database;
	delete statemachine;

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
		QString name = QString::fromStdString(std::get<0>(ingrediant));
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
	QItemSelectionModel *select=ui->addingrediant_list->selectionModel();
	if (select->hasSelection()) {
		QModelIndexList list= select->selectedRows();
		for (auto it =list.begin();it!=list.end();it++){
			int row=it->row();
			QModelIndex index = ingrediants_model->index(row, 0,
					QModelIndex());
			std::string name = ingrediants_model->data(index).toString().toStdString();
			database->removeIngrediant(name);
			ingrediants_model->removeRow(row,QModelIndex());

		}
	}
}

