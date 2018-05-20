#include <QApplication>
#include "mainwindow.h"
int main(int argc, char *argv[]) {
	qputenv("QT_IM_MODULE", QByteArray("vkim"));

		QApplication app(argc, argv);
	MainWindow w;
	  w.showFullScreen();
	  return app.exec();
 }

