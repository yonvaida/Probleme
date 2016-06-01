#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <qobject.h>
#include "snakeWithTest\main.h"
#include <iostream>

class boardGui :public QGraphicsRectItem {
	//Q_OBJECT
public:
	void keyPressEvent(QKeyEvent * event);
	Direction direction=Direction::right;
};