#include "snake.h"
#include <QKeyEvent>
#include <QTimer>
#include <qobject.h>

snakeRect::snakeRect() {
	setRect(0, 0, 5, 5);
	QTimer * timer = new QTimer();
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	timer->start(1000);
}
void snakeRect::keyPressEvent(QKeyEvent* event) {

		QTimer * timer = new QTimer();
		QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
		timer->start(1000);

		if (event->key() == Qt::Key_Up) {
		
	}

}
void snakeRect::move() {
	
		setPos(x() + 10, y());
	
		
	
	
}