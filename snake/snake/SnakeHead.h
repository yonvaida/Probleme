#pragma once
#include <QGraphicsRectItem>
#include <qobject.h>


#include <qdebug.h>
class snakeRect : public QObject,public QGraphicsRectItem {
Q_OBJECT
public:
	snakeRect();
	void keyPressEvent(QKeyEvent * event);
	void move();

	
	
};

