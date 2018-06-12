#include <QApplication>
#include "mainwindow.h"
#include <csignal>
void signalhandler(int sig) {
	if (sig == SIGINT) {
		printf("will quit by SIGINT\n");
		qApp->quit();
	} else if (sig == SIGTERM) {
		printf("will quit by SIGTERM\n");
		qApp->quit();
	}
}

int main(int argc, char *argv[]) {
	qputenv("QT_IM_MODULE", QByteArray("vkim"));

	QApplication app(argc, argv);
	MainWindow w;
	signal(SIGINT,signalhandler);
	signal(SIGTERM,signalhandler);
	QObject::connect(&app, SIGNAL(aboutToQuit()),&w,SLOT(cleanup()));
	w.showFullScreen();
	return app.exec();
}

