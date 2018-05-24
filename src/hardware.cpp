/*
 * hardware.cpp
 *
 *  Created on: May 24, 2018
 *      Author: martin
 */
#include "hardware.h"

Hardware::Hardware(QObject* _parent):QObject(_parent){

}

Hardware::~Hardware(){

}

void Hardware::run(){
	std::this_thread::sleep_for (std::chrono::seconds(3));
	Q_EMIT(updated());
}

void Hardware::pour(int tank, int amount){
	(void)tank;
	(void)amount;
	if(thr!=NULL){
		delete thr;
	}
	thr = new boost::thread(boost::bind(&Hardware::run, this));

}
