/*
 * statemachine.h
 *
 *  Created on: Apr 10, 2018
 *      Author: martin
 */

#ifndef INCLUDE_STATEMACHINE_H_
#define INCLUDE_STATEMACHINE_H_
#include <QObject>

enum Widgets { frontpage, mainpage, adminpage,loginpage,drinkpage,adduserpage };

class StateMachine: public QObject {
	Q_OBJECT
public:
	StateMachine(QObject* _parent = NULL);
	~StateMachine();
protected:
private:
	Q_SIGNALS:
	void changeWidget(int);
	public Q_SLOTS:
	void make_a_drink();
	void admin();
	void scoreboard();
	void startpage_pressed();
	void login_ok();
	void login_cancel();
	void drink_back();
	void add_user();
};

#endif /* INCLUDE_STATEMACHINE_H_ */
