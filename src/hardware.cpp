/*
 * hardware.cpp
 *
 *  Created on: May 24, 2018
 *      Author: martin
 */
#include "hardware.h"

Hardware::Hardware(QObject* _parent) :
		QObject(_parent) {
	//export all gpios
	std::ofstream exportgpio(export_str.c_str()); //Open export file
	if (!exportgpio.is_open()) {
		std::cout << " OPERATION FAILED: Unable to open export file" << std::endl;
		return;
	}
	std::cout<<"hello from hardware2"<<std::endl;
	for (auto it : gpios) {
		std::cout<<it<<std::endl;
		exportgpio << it;
	}
	exportgpio.close();

	//set all outputs to output

	for (auto it : outputs) {
		std::ofstream setdirgpio((it + "/direction").c_str());
		if (!setdirgpio.is_open()) {
			std::cout << " OPERATION FAILED: Unable to set direction for GPIO "<<it
					<< std::endl;
			continue;
		}

		setdirgpio << "out"; //write direction to direction file
		setdirgpio.close(); // close direction file

	}

	//set all inputs to input
	for (auto it : inputs) {
		std::ofstream setdirgpio((it + "/direction").c_str());
		if (!setdirgpio.is_open()) {
			std::cout << " OPERATION FAILED: Unable to set direction for GPIO "<<it
					<< std::endl;
			continue;
		}

		setdirgpio << "in"; //write direction to direction file
		setdirgpio.close(); // close direction file

	}

}

void Hardware::openValve() {
	std::ofstream setvalgpio((in1_hbridgeStr + "/value").c_str()); // open value file for gpio
	if (!setvalgpio.is_open()) {
		std::cout << " OPERATION FAILED: Unable to set the value of GPIO "<<in1_hbridgeStr
				<< std::endl;
		return;
	}

	std::ofstream setvalgpio0((in3_hbridgeStr + "/value").c_str()); // open value file for gpio
	if (!setvalgpio0.is_open()) {
		std::cout << " OPERATION FAILED: Unable to set the value of GPIO "<<in3_hbridgeStr
				<< std::endl;
		return;
	}

	setvalgpio << "1"; //write value to value file
	setvalgpio.flush();
	setvalgpio0 << "1"; //write value to value file
	setvalgpio0.flush();
	usleep(usecondsToChangeValve);
	setvalgpio << "0";
	setvalgpio.flush();
	setvalgpio0 << "0";
	setvalgpio0.flush();
	setvalgpio.close(); // close value file
	setvalgpio0.close();
}

void Hardware::goToPos(int _pos) {
	int posInSteps = stepsToTake[_pos];
	int stepsFromCurrentPos = posInSteps - currentPos;
	bool direction = stepsFromCurrentPos < 0;

	//set direction
	std::ofstream dirgpio((dirStr + "/value").c_str()); // open value file for gpio
	if (!dirgpio.is_open()) {
		std::cout << " OPERATION FAILED: Unable to set the value of dir GPIO"
				<< std::endl;
		return;
	}
	dirgpio << direction;
	dirgpio.close();
	stepsFromCurrentPos=abs(stepsFromCurrentPos);
	std::ofstream stepgpio((stepStr + "/value").c_str()); // open value file for gpio
	if (!stepgpio.is_open()) {
		std::cout << " OPERATION FAILED: Unable to set the value of step GPIO"
				<< std::endl;
		return;
	}
	for (int i =0;i<stepsFromCurrentPos;i++){
		stepgpio<<true;
		usleep(100);
		stepgpio<<false;
		usleep(100);
	}
	stepgpio.close();
	currentPos=posInSteps;

}

void Hardware::calibrate(){
	goToPos(0);
	//set direction
	std::ofstream dirgpio((dirStr + "/value").c_str()); // open value file for gpio
	if (!dirgpio.is_open()) {
		std::cout << " OPERATION FAILED: Unable to set the value of dir GPIO"
				<< std::endl;
		return;
	}
	std::ofstream stepgpio((stepStr + "/value").c_str()); // open value file for gpio
	if (!stepgpio.is_open()) {
		std::cout << " OPERATION FAILED: Unable to set the value of step GPIO"
				<< std::endl;
		return;
	}
	//go in
	dirgpio<<0;
	dirgpio.close();
	while (true){
		for (int i =0;i<10;i++){
			stepgpio<<1;
			usleep(100);
			stepgpio<<0;
			usleep(100);
		}
		if(calButtonPressed()){
			currentPos=0;
			stepgpio.close();
			return;
		}
	}


}
void Hardware::closeValve() {
	std::ofstream setvalgpio((in2_hbridgeStr + "/value").c_str()); // open value file for gpio
	if (!setvalgpio.is_open()) {
		std::cout << " OPERATION FAILED: Unable to set the value of GPIO"<<in2_hbridgeStr
				<< std::endl;
		return;
	}

	std::ofstream setvalgpio0((in4_hbridgeStr + "/value").c_str()); // open value file for gpio
	if (!setvalgpio0.is_open()) {
		std::cout << " OPERATION FAILED: Unable to set the value of GPIO"<<in4_hbridge
				<< std::endl;
		return;
	}

	setvalgpio << "1"; //write value to value file
	setvalgpio.flush();
	setvalgpio0 << "1"; //write value to value file
	setvalgpio0.flush();
	usleep(usecondsToChangeValve);
	setvalgpio << "0";
	setvalgpio.flush();
	setvalgpio0 << "0";
	setvalgpio0.flush();
	setvalgpio.close(); // close value file
	setvalgpio0.close();
}
bool Hardware::calButtonPressed() {
	std::ifstream getvalgpio((cal_buttonStr + "/value").c_str()); // open value file for gpio
	if (!getvalgpio.is_open()) {
		std::cout << " OPERATION FAILED: Unable to get value of GPIO"
				<< std::endl;
		return false;
	}
	bool val = false;
	getvalgpio >> val;  //read gpio value
	getvalgpio.close(); //close the value file
	return val;
}

Hardware::~Hardware() {

}

void Hardware::run() {
	//std::this_thread::sleep_for(std::chrono::seconds(3));
	goToPos(tank);
	openValve();
	usleep(clperusec*amount);
	closeValve();
	runs++;
	if(runs>runsPerCalibration){
		calibrate();
		runs=0;
	}

	Q_EMIT(updated());
}

void Hardware::pour(int _tank, int _amount) {
	tank=_tank;
	amount=_amount;
	if (thr != NULL) {
		delete thr;
	}
	thr = new boost::thread(boost::bind(&Hardware::run, this));

}
