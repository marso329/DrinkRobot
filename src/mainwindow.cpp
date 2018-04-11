#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent), ui(new Ui::MainWindow),statemachine(new StateMachine()) {
	ui->setupUi(this);
	database=new DataBase();
	ingrediants_model = new QStandardItemModel(0,3,this);
	ingrediants_model->setHorizontalHeaderItem(0, new QStandardItem(QString("Ingrediant")));
	ingrediants_model->setHorizontalHeaderItem(1, new QStandardItem(QString("Strength[%]")));
	ingrediants_model->setHorizontalHeaderItem(2, new QStandardItem(QString("Price[kr/l]")));
	ui->addingrediant_list->setModel(ingrediants_model);
	//connect statemachine to stackedwidget
	this->ui->stackedWidget->setCurrentIndex(0);
	connect(this->statemachine, SIGNAL(changeWidget(int)),ui->stackedWidget, SLOT(setCurrentIndex(int)));
	connect(this->statemachine, SIGNAL(set_add_ingrediant()),this, SLOT(set_add_ingrediant()));
	connect(ui->addingrediant_ok,SIGNAL(clicked()),this,SLOT(add_ingrediant_ok()));

	//connected to statemachine
	connect(ui->graphicsView,SIGNAL(clicked()),this->statemachine,SLOT(startpage_pressed()));
	connect(ui->make_a_drink,SIGNAL(clicked()),this->statemachine,SLOT(make_a_drink()));
	connect(ui->admin,SIGNAL(clicked()),this->statemachine,SLOT(admin()));
	connect(ui->admin_back,SIGNAL(clicked()),this->statemachine,SLOT(admin_back()));
	connect(ui->login_cancel,SIGNAL(clicked()),this->statemachine,SLOT(login_cancel()));
	connect(ui->login_ok,SIGNAL(clicked()),this->statemachine,SLOT(login_ok()));
	connect(ui->drink_back,SIGNAL(clicked()),this->statemachine,SLOT(drink_back()));
	connect(ui->add_user,SIGNAL(clicked()),this->statemachine,SLOT(add_user()));
	connect(ui->adduser_ok,SIGNAL(clicked()),this,SLOT(add_user()));
	connect(ui->add_ingredient,SIGNAL(clicked()),this->statemachine,SLOT(add_ingrediant()));
	connect(ui->addingrediant_back,SIGNAL(clicked()),this->statemachine,SLOT(add_ingrediant_back()));

	//connected to this class

}
void MainWindow::add_user(){
	std::string name =ui->name_input->text().toStdString();
	std::string pass =ui->pass_input->text().toStdString();
	bool admin =ui->admin_input->isChecked();
	database->addUser(name,pass,admin);
	statemachine->add_user_ok();

}


MainWindow::~MainWindow() {
	delete database;
	delete statemachine;

}

void MainWindow::set_add_ingrediant(){
	std::vector<std::tuple<std::string,int,int>> ingredients=database->getIngrediants();
	//clear previous data
	ingrediants_model->removeRows( 0, ingrediants_model->rowCount() );
	int counter=0;
	for (auto it= ingredients.begin();it!=ingredients.end();it++){
		std::tuple<std::string,int,int> ingrediant=(*it);
		QString name =QString::fromStdString(std::get<0>(ingrediant));
		int strength=std::get<1>(ingrediant);
		int price=std::get<2>(ingrediant);
		QString strength_str=QString::fromStdString(std::to_string(strength));
		QString price_str=QString::fromStdString(std::to_string(price));
		ingrediants_model->setItem(counter,0,new QStandardItem(name));
		ingrediants_model->setItem(counter,1,new QStandardItem(strength_str));
		ingrediants_model->setItem(counter,2,new QStandardItem(price_str));
		counter++;

	}
	ingrediants_model->sort( 0, Qt::AscendingOrder );

}

void MainWindow::add_ingrediant_ok(){
	std::string name =ui->addingrediant_name->text().toStdString();
	ui->addingrediant_name->clear();

	int strength= ui->addingrediant_strength->value();
	ui->addingrediant_strength->clear();
	int price= ui->addingrediant_price->value();
	ui->addingrediant_price->clear();
	database->addIngrediant(name,strength,price);
	this->set_add_ingrediant();

}

