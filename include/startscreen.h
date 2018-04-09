/*
 * startscreen.h
 *
 *  Created on: Apr 9, 2018
 *      Author: martin
 */

#ifndef INCLUDE_STARTSCREEN_H_
#define INCLUDE_STARTSCREEN_H_
#include <QWidget>
#include <QObject>
#include <QGraphicsScene>
#include <QFontDatabase>
#include <QFont>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QMouseEvent>

class StartScreen:public QGraphicsView{
	Q_OBJECT
public:
	StartScreen(QWidget *_parent=NULL);
	~StartScreen();
	void mousePressEvent(QMouseEvent *event);
private:
	QGraphicsScene* scene;
	Q_SIGNALS:
	void clicked();
	public Q_SLOTS:

};

/**
 *
 * border-image: url(:images/metal.jpg) 0 0 0 0 stretch stretch;
 */



#endif /* INCLUDE_STARTSCREEN_H_ */
