#include "snakeHead.h"
#include <QKeyEvent>
#include <qstring.h>
#include <qobject.h>
#include <qdebug.h>
#include <vector>

snakeRect::snakeRect() {
	setRect(0, 0, 5, 5);
	
}
QString direction;
void snakeRect::keyPressEvent(QKeyEvent* event) {
	if (event->key() == Qt::Key_Up) {
		direction = "up";
	}
	if (event->key() == Qt::Key_Down) {
		direction = "down";
	}
	if (event->key() == Qt::Key_Left) {
		direction = "left";
	}
	if (event->key() == Qt::Key_Right) {
		direction = "right";
	}	
}
void snakeRect::move() {
	if (direction == "up") {
		setPos(x(), y() - 10);
	}
	else if (direction == "down") {
		setPos(x(), y() + 10);
	}
	else if (direction == "left") {
		setPos(x() - 10, y());
	}
	else if (direction == "right") {
		setPos(x() + 10, y());
	}
};


	
