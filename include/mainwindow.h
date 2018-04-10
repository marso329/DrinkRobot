
#ifndef MAINWINDOW_
#define MAINWINDOW_
#include "ui_mainwindow.h"
#include "statemachine.h"
#include "database.h"

class MainWindow: public QMainWindow {
	Q_OBJECT
public:
	MainWindow(QWidget* parent = 0);
	~MainWindow();
private:
	Ui::MainWindow* ui;
	StateMachine* statemachine;
	DataBase* database;
protected:
Q_SIGNALS:

public Q_SLOTS:
	void add_user();

};
#endif
