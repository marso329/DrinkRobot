#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	connect(ui->graphicsView, SIGNAL(clicked()), this, SLOT(startScreenDone()));
}


MainWindow::~MainWindow() {

}

void MainWindow::startScreenDone(){
	ui->stackedWidget->setCurrentIndex(1);
}

