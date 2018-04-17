#ifndef MAINWINDOW_
#define MAINWINDOW_
#include "ui_mainwindow.h"
#include "statemachine.h"
#include "database.h"
#include <QStandardItemModel>
#include <QItemDelegate>

class IntRangeValidator: public QValidator {
Q_OBJECT
public:
	IntRangeValidator(QObject* parent = 0) :
		QValidator(parent) {

	}
	IntRangeValidator(QObject* parent = 0,int min=0,int max=500) :
		QValidator(parent),min(min),max(max) {

	}
	QValidator::State validate(QString& input, int&) const {
		int temp;
		try {
			temp = std::stoi(input.toStdString());
		} catch (std::invalid_argument& e) {
			return QValidator::State::Invalid;
		}
		if(temp<max &&temp>min){
			return QValidator::State::Acceptable;
		}
		else{
			return QValidator::State::Invalid;
		}
	}
	int min=0;
	int max=500;
};

class NotEditableDelegate: public QItemDelegate {
Q_OBJECT
public:
	explicit NotEditableDelegate(QObject *parent = 0) :
			QItemDelegate(parent) {
	}

protected:
	bool editorEvent(QEvent *event, QAbstractItemModel *model,
			const QStyleOptionViewItem &option, const QModelIndex &index) {
		(void) event;
		(void) model;
		(void) option;
		(void) index;

		return false;
	}
	QWidget* createEditor(QWidget *, const QStyleOptionViewItem &,
			const QModelIndex &) const {
		return Q_NULLPTR;
	}

};

class IntRangeDelegate: public QItemDelegate {
public:
	IntRangeDelegate(QObject* _parent=NULL,int min=0,int max=500):QItemDelegate(_parent),min(min),max(max){

	}
	QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem & option,
			const QModelIndex & index) const {
		(void) option;
		(void) index;
		QLineEdit *lineEdit = new QLineEdit(parent);
		// Set validator
		IntRangeValidator *validator = new IntRangeValidator( lineEdit,min,max);
		lineEdit->setValidator(validator);
		return lineEdit;
	}
	int min=0;
	int max=500;
};

class MainWindow: public QMainWindow {
Q_OBJECT
public:
	MainWindow(QWidget* parent = 0);
	~MainWindow();
private:
	Ui::MainWindow* ui;
	StateMachine* statemachine;
	DataBase* database;
	QStandardItemModel *ingrediants_model;
	bool settings_up_ingredients=false;
protected:
Q_SIGNALS:

public Q_SLOTS:
	void add_user();
	void set_add_ingrediant();
	void add_ingrediant_ok();
	void ingrediantDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles );
	void remove_ingrediant();
	void set_levels();
	void set_levels_done();
};
#endif
