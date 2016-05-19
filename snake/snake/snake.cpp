#include "snake.h"
#include <QKeyEvent>
#include <QTimer>
#include <qobject.h>
#include <qdebug.h>

snakeRect::snakeRect() {
	setRect(0, 0, 5, 5);
	
}
void snakeRect::keyPressEvent(QKeyEvent* event) {
	int temp;
	if (event->key() == Qt::Key_Up) {
		temp = 1;
	}
	if (event->key() == Qt::Key_Down) {
		temp = 2;
	}

		QTimer * timer = new QTimer();
		QObject::connect(timer, &QTimer::timeout, [=]() {
			if (temp==1) {
				moveBy(0, -10);
			};
			if (temp==2) {
				moveBy(0,10);
			};
		
		});
		timer->start(1000);
		
		

}
void snakeRect::move() {
	
		setPos(x() + 10, y());
	
		
	
	
}