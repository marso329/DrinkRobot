#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent), ui(new Ui::MainWindow),statemachine(new StateMachine()) {
	ui->setupUi(this);
	database=new DataBase();
	//connect statemachine to stackedwidget
	this->ui->stackedWidget->setCurrentIndex(0);
	connect(this->statemachine, SIGNAL(changeWidget(int)),ui->stackedWidget, SLOT(setCurrentIndex(int)));

	//connected to statemachine
	connect(ui->graphicsView,SIGNAL(clicked()),this->statemachine,SLOT(startpage_pressed()));
	connect(ui->make_a_drink,SIGNAL(clicked()),this->statemachine,SLOT(make_a_drink()));
	connect(ui->admin,SIGNAL(clicked()),this->statemachine,SLOT(admin()));
	connect(ui->login_cancel,SIGNAL(clicked()),this->statemachine,SLOT(login_cancel()));
	connect(ui->login_ok,SIGNAL(clicked()),this->statemachine,SLOT(login_ok()));
	connect(ui->drink_back,SIGNAL(clicked()),this->statemachine,SLOT(drink_back()));
	connect(ui->add_user,SIGNAL(clicked()),this->statemachine,SLOT(add_user()));
	connect(ui->adduser_ok,SIGNAL(clicked()),this,SLOT(add_user()));

	//connected to this class

}
void MainWindow::add_user(){
	std::string name =ui->name_input->text().toStdString();
	std::string pass =ui->pass_input->text().toStdString();
	bool admin =ui->admin_input->isChecked();
	database->addUser(name,pass,admin);
	statemachine->startpage_pressed();

}


MainWindow::~MainWindow() {
	delete database;
	delete statemachine;

}


