/*
 * temperature_controller.cpp
 *
 *  Created on: May 21, 2018
 *      Author: martin
 */
#include "temperature_controller.h"

TemperatureController::TemperatureController(QObject* _parent) :
		QObject(_parent) {
	set_temperaturs = std::vector<std::atomic_int*>(10);
	actual_temperaturs = std::vector<std::atomic_int*>(10);
	for (int i = 0; i < 10; i++) {

		set_temperaturs[i] = new std::atomic_int;
		set_temperaturs[i]->store(0);
		actual_temperaturs[i] = new std::atomic_int;
		actual_temperaturs[i]->store(0);
	}
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start(1000);

	char portname[] = "/dev/ttyUSB0";
	fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
	if (fd < 0) {
		printf("error %d opening %s: %s", errno, portname, strerror(errno));
	}

	set_interface_attribs(fd, B9600, 0);
	set_blocking(fd, 0);

}
TemperatureController::~TemperatureController() {

}

std::vector<int> TemperatureController::get_temperaturs() {
	std::vector<int> to_return;
	for (auto it = actual_temperaturs.begin(); it != actual_temperaturs.end();
			it++) {
		int temp = **(it);
		to_return.push_back(temp);
	}
	return to_return;
}
void TemperatureController::set_temperature(int index, int value) {
	if (index >= 0 && index < 10) {
		set_temperaturs[index]->store(value);
	}
}

//convert to real temperature
int TemperatureController::convert(int value) {
	return value / 30;
}

void TemperatureController::power_on(int index) {
	if (index < 8) {
		char value = 'A';
		value += index;
		char to_send[1];
		to_send[0] = value;
		int written = write(fd, to_send, 1);
		if (written < 1) {
			std::cout << "writing to temp controller failed" << std::endl;
		}
	}
	else if(index==8){
		char to_send[2];
		to_send[0] = 'I';
		to_send[1] = 'J';
		int written = write(fd, to_send, 2);
		if (written < 1) {
			std::cout << "writing to temp controller failed" << std::endl;
		}
	}
	else if(index==9){
		char to_send[2];
		to_send[0] = 'K';
		to_send[1] = 'L';
		int written = write(fd, to_send, 2);
		if (written < 1) {
			std::cout << "writing to temp controller failed" << std::endl;
		}
	}
	usleep(2500);
}
void TemperatureController::power_off(int index) {
	if (index < 8) {
		char value = 'a';
		value += index;
		char to_send[1];
		to_send[0] = value;
		int written = write(fd, to_send, 1);
		if (written < 1) {
			std::cout << "writing to temp controller failed" << std::endl;
		}
	}
	else if(index==8){
		char to_send[2];
		to_send[0] = 'i';
		to_send[1] = 'j';
		int written = write(fd, to_send, 2);
		if (written < 1) {
			std::cout << "writing to temp controller failed" << std::endl;
		}
	}
	else if(index==9){
		char to_send[2];
		to_send[0] = 'k';
		to_send[1] = 'l';
		int written = write(fd, to_send, 2);
		if (written < 1) {
			std::cout << "writing to temp controller failed" << std::endl;
		}
	}
	usleep(2500);
}

void TemperatureController::update() {
	//update temperatures
	for (int i = 0; i < 10; i++) {
		char value = '0';
		value += i;
		char to_send[1];
		to_send[0] = value;
		int written = write(fd, to_send, 1);
		if (written < 1) {
			std::cout << "writing to temp controller failed" << std::endl;
		}
		usleep(2500);
		char buf[2];
		int n = read(fd, buf, sizeof(buf));
		if (n >= 2) {
			short unsigned data = 0;
			data = *((short unsigned*) buf);
			*(actual_temperaturs[i]) = convert((int) data);
		}
	}

	//set peltier element on or off
	for (int i = 0; i < 10; i++) {
		if (actual_temperaturs[i]->load() > set_temperaturs[i]->load()) {
			power_on(i);
		} else {
			power_off(i);
		}
	}

	Q_EMIT(updated());
}

int TemperatureController::set_interface_attribs(int fd, int speed,
		int parity) {
	struct termios tty;
	memset(&tty, 0, sizeof tty);
	if (tcgetattr(fd, &tty) != 0) {
		printf("error %d from tcgetattr", errno);
		return -1;
	}

	cfsetospeed(&tty, speed);
	cfsetispeed(&tty, speed);

	tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
	// disable IGNBRK for mismatched speed tests; otherwise receive break
	// as \000 chars
	tty.c_iflag &= ~IGNBRK;         // disable break processing
	tty.c_lflag = 0;                // no signaling chars, no echo,
									// no canonical processing
	tty.c_oflag = 0;                // no remapping, no delays
	tty.c_cc[VMIN] = 0;            // read doesn't block
	tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

	tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

	tty.c_cflag |= (CLOCAL | CREAD); // ignore modem controls,
									 // enable reading
	tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
	tty.c_cflag |= parity;
	tty.c_cflag &= ~CSTOPB;
	tty.c_cflag &= ~CRTSCTS;

	if (tcsetattr(fd, TCSANOW, &tty) != 0) {
		printf("error %d from tcsetattr", errno);
		return -1;
	}
	return 0;
}

void TemperatureController::set_blocking(int fd, int should_block) {
	struct termios tty;
	memset(&tty, 0, sizeof tty);
	if (tcgetattr(fd, &tty) != 0) {
		printf("error %d from tggetattr", errno);
		return;
	}

	tty.c_cc[VMIN] = should_block ? 1 : 0;
	tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

	if (tcsetattr(fd, TCSANOW, &tty) != 0)
		printf("error %d setting term attributes", errno);
}

