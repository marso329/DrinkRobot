/*
 * startscreen.cpp
 *
 *  Created on: Apr 9, 2018
 *      Author: martin
 */
#include "startscreen.h"
#include <iostream>

StartScreen::StartScreen(QWidget* _parent) :
		QGraphicsView(_parent) {

	scene = new QGraphicsScene(this);

	QImage image;
	image.load(":images/start.png");
	QPixmap pixmap = QPixmap::fromImage(image);
	QGraphicsPixmapItem* item = new QGraphicsPixmapItem(pixmap);
	//item->setScale(0.1);
	item->setFlags(
			QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
	item->setPos(scene->sceneRect().width() / 2.0,
			scene->sceneRect().height() / 2.0);
	scene->addItem(item);

	this->setScene(scene);
	this->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}
StartScreen::~StartScreen() {

}

void StartScreen::mousePressEvent(QMouseEvent *event){
	event->accept();
	Q_EMIT clicked();
}

