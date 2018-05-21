/*
 * temperature_controller.h
 *
 *  Created on: May 21, 2018
 *      Author: martin
 */

#ifndef INCLUDE_TEMPERATURE_CONTROLLER_H_
#define INCLUDE_TEMPERATURE_CONTROLLER_H_

#include <QObject>
#include <QTimer>

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#include <atomic>
#include <iostream>



class TemperatureController : public QObject  {
Q_OBJECT
public:
	TemperatureController(QObject* _parent = NULL);
	~TemperatureController();
	std::vector<int> get_temperaturs();
	void set_temperature(int,int);
private:
	int set_interface_attribs(int fd, int speed, int parity);
	void set_blocking(int fd, int should_block);
	int convert(int);
	void power_on(int);
	void power_off(int);

	std::vector<std::atomic_int*> set_temperaturs;
	std::vector<std::atomic_int*> actual_temperaturs;
	QTimer *timer;
	int fd;
	public Q_SLOTS:
	void update();

	Q_SIGNALS:
	void updated();



};

#endif /* INCLUDE_TEMPERATURE_CONTROLLER_H_ */
