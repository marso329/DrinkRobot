/*
 * statemachine.h
 *
 *  Created on: Apr 10, 2018
 *      Author: martin
 */

#ifndef INCLUDE_STATEMACHINE_H_
#define INCLUDE_STATEMACHINE_H_
#include <QObject>

class StateMachine: public QObject {
	Q_OBJECT
public:
	StateMachine(QObject* _parent = NULL);
	~StateMachine();
protected:
private:

};

#endif /* INCLUDE_STATEMACHINE_H_ */
