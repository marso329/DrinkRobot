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
#include <string>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

/**
 * GPIO21: in1 on h bridge
 * GPIO20: in2 on h bridge
 * GPIO16: in3 on h bridge
 * GPIO26: in4 on h bridge
 * GPIO19: step
 * GPIO13: dir
 * GPIO6 : calibration button, pulled down, high when pressed
 * GPIO5 : calibration button valve, pulled down, high when pressed
 */
class Hardware : public QObject  {
Q_OBJECT
public:
	Hardware(QObject* _parent = NULL);
	~Hardware();
	//will pour amount cl from tank
	void pour(int tank, int amount);
private:
	bool calButtonPressed();
	bool calButtonValvePressed();
	void openValve();
	void closeValve();
	void goToPos(int _pos);
	void goRelPos(int _pos);
	void calibrate();
	void calibrateValve();
	boost::thread* thr=NULL;
	std::string export_str = "/sys/class/gpio/export";
	std::string unexport_str = "/sys/class/gpio/unexport";
	int in1_hbridge=21;
	std::string in1_hbridgeStr="/sys/class/gpio/gpio21";
	int in2_hbridge=20;
	std::string in2_hbridgeStr="/sys/class/gpio/gpio20";
	int in3_hbridge=16;
	std::string in3_hbridgeStr="/sys/class/gpio/gpio16";
	int in4_hbridge=26;
	std::string in4_hbridgeStr="/sys/class/gpio/gpio26";
	int step=19;
	std::string stepStr="/sys/class/gpio/gpio19";
	int dir =13;
	std::string dirStr="/sys/class/gpio/gpio13";

	int cal_button=6;
	std::string cal_buttonStr="/sys/class/gpio/gpio6";
	int cal_button_valve=5;
	std::string cal_buttonValveStr="/sys/class/gpio/gpio5";

	int usecondsToChangeValve =4000000;
	std::vector<int> gpios={in1_hbridge,in2_hbridge,in3_hbridge,in4_hbridge,step,dir,cal_button};
	std::vector<std::string> outputs={in1_hbridgeStr,in2_hbridgeStr,in3_hbridgeStr,in4_hbridgeStr,stepStr,dirStr};
	std::vector<std::string> inputs={cal_buttonStr};

	//stepper
	std::vector<int> stepsToTake={200,700,1190,1680,2180,450,950,1430,1930,2420};
	int currentPos=0;
	int runs=0;
	int runsPerCalibration=10;
	int clperusec=0;
	int tank=0;
	int amount=0;
	void run();
	Q_SIGNALS:
	void updated();
};




#endif /* INCLUDE_HARDWARE_H_ */
