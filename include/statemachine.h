/*
 * statemachine.h
 *
 *  Created on: Apr 10, 2018
 *      Author: martin
 */

#ifndef INCLUDE_STATEMACHINE_H_
#define INCLUDE_STATEMACHINE_H_
#include <QObject>

enum Widgets { frontpage, mainpage, adminpage,loginpage,drinkpage,adduserpage,addingrediantpage,setlevelspage };

class StateMachine: public QObject {
	Q_OBJECT
public:
	StateMachine(QObject* _parent = NULL);
	~StateMachine();
protected:
private:
	Q_SIGNALS:

	//buttons
	void changeWidget(int);
	void set_add_ingrediant();
	public Q_SLOTS:
	void make_a_drink();
	void admin();
	void admin_back();
	void scoreboard();
	void startpage_pressed();
	void login_ok();
	void login_cancel();
	void drink_back();
	void add_user();
	void add_user_ok();
	void add_ingrediant();
	void add_ingrediant_back();
	void set_levels_back();
	void set_levels();

	//update something
};

#endif /* INCLUDE_STATEMACHINE_H_ */
