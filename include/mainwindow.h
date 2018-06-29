#ifndef MAINWINDOW_
#define MAINWINDOW_
#include "ui_mainwindow.h"
#include "statemachine.h"
#include "database.h"
#include "temperature_controller.h"

#include <QStandardItemModel>
#include <QItemDelegate>
#include <QGroupBox>
#include "ui_password.h"
#include "ui_iconselector.h"
#include "ui_loading.h"
#include "itemdelegate.h"
#include <QDirIterator>
#include <QDebug>
#include <QToolButton>
#include <QMovie>
#include "hardware.h"
#include <cstdlib>

enum NextStage {make_a_drink,admin,none};
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
	void load_icons();
	void load_gifs();
	Ui::MainWindow* ui;
	StateMachine* statemachine;
	TemperatureController* tempcontroller;
	Hardware* hardware;
	DataBase* database;
	QStandardItemModel *ingrediants_model;
	std::string current_user;
	QStandardItemModel *user_model;
	QStandardItemModel *drink_model;
	QStandardItemModel *scoreboard_most_model;
	QStandardItemModel *scoreboard_heighest_model;
	QStandardItemModel *scoreboard_spent_model;
	std::map<std::string,QIcon> icons;
	std::vector<QMovie*> gifs;
	bool settings_up_ingredients=false;
	bool settings_up_users=false;
	bool settings_up_drinks=false;
	NextStage next_stage;
	std::vector<std::tuple<int,int>> tanksAmount;
	Ui_Loading* loading;
protected:
Q_SIGNALS:
void closeDialog(int);
void closeLoading(int);

public Q_SLOTS:
	void select_icon();
	void select_icon_callback();
	void drink_changed(const QString &text);
	void setup_make_drink();
	void drink_selected();
	void make_drink();
	void setup_login();
	void user_pressed();
	void admin();
	void add_user();
	void set_add_ingrediant();
	void passwordFunc();
	void set_add_user();
	void add_ingrediant_ok();
	void ingrediantDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles );
	void userDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles );
	void remove_ingrediant();
	void remove_drink();
	void remove_user();
	void set_levels();
	void set_levels_done();
	void set_add_drink();
	void add_drink();
	void set_temp_changed(int value);
	void setup_temps_from_database();
	void add_ingredient_to_drink();
	void drinkDataChanged(const QModelIndex &topLeft,
			const QModelIndex &bottomRight, const QVector<int> &roles);
	void update_temperatures();
	void setup_scoreboard();
	void update_loading();
	void clear_user();
	void cleanup();
};
#endif
