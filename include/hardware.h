/*
 * hardware.h
 *
 *  Created on: May 24, 2018
 *      Author: martin
 */

#ifndef INCLUDE_HARDWARE_H_
#define INCLUDE_HARDWARE_H_
#include <QObject>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
#include <boost/thread.hpp>

class Hardware : public QObject  {
Q_OBJECT
public:
	Hardware(QObject* _parent = NULL);
	~Hardware();
	//will pour amount cl from tank
	void pour(int tank, int amount);
private:
	boost::thread* thr=NULL;
	void run();
	Q_SIGNALS:
	void updated();


};




#endif /* INCLUDE_HARDWARE_H_ */
