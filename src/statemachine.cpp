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
	Q_EMIT changeWidget(Widgets::drinkpage);

}
void StateMachine::admin(){
	Q_EMIT changeWidget(Widgets::adminpage);
}

void StateMachine::login(){
	Q_EMIT changeWidget(Widgets::loginpage);
}



void StateMachine::admin_back(){
	Q_EMIT changeWidget(Widgets::mainpage);
}

void StateMachine::scoreboard(){

}
void StateMachine::startpage_pressed(){
	Q_EMIT changeWidget(Widgets::mainpage);
}

void StateMachine::drink_back(){
	Q_EMIT changeWidget(Widgets::mainpage);
}

void StateMachine::add_user(){
	Q_EMIT changeWidget(Widgets::adduserpage);
}

void StateMachine::add_user_back(){
	Q_EMIT changeWidget(Widgets::adminpage);
}

void StateMachine::add_user_ok(){
	Q_EMIT changeWidget(Widgets::adminpage);
}

void StateMachine::add_ingrediant(){
	Q_EMIT set_add_ingrediant();
	Q_EMIT changeWidget(Widgets::addingrediantpage);
}

void StateMachine::add_ingrediant_back(){
	Q_EMIT changeWidget(Widgets::adminpage);
}
void StateMachine::set_levels_back(){
	Q_EMIT changeWidget(Widgets::adminpage);
}

void StateMachine::set_levels(){
	Q_EMIT changeWidget(Widgets::setlevelspage);
}

void StateMachine::set_add_drink(){
	Q_EMIT changeWidget(Widgets::adddrinkpage);
}

void StateMachine::add_drink_back(){
	Q_EMIT changeWidget(Widgets::adminpage);
}

void StateMachine::set_temp_back(){
	Q_EMIT changeWidget(Widgets::adminpage);
}
void StateMachine::set_temp(){
	Q_EMIT changeWidget(Widgets::settemppage);
}


