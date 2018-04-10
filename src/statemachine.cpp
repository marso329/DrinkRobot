/*
 * statemachine.cpp
 *
 *  Created on: Apr 10, 2018
 *      Author: martin
 */


#include "statemachine.h"

StateMachine::StateMachine(QObject* _parent):QObject(_parent){
}

StateMachine::~StateMachine(){

}
void StateMachine::make_a_drink(){
	Q_EMIT changeWidget(Widgets::loginpage);

}
void StateMachine::admin(){
	Q_EMIT changeWidget(Widgets::adminpage);

}
void StateMachine::scoreboard(){

}
void StateMachine::startpage_pressed(){
	Q_EMIT changeWidget(Widgets::mainpage);
}
void StateMachine::login_ok(){
	Q_EMIT changeWidget(Widgets::drinkpage);
}
void StateMachine::login_cancel(){
	Q_EMIT changeWidget(Widgets::mainpage);
}

void StateMachine::drink_back(){
	Q_EMIT changeWidget(Widgets::mainpage);
}

void StateMachine::add_user(){
	Q_EMIT changeWidget(Widgets::adduserpage);
}

