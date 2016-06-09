#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <qobject.h>
#include <qlabel.h>
#include "snakeWithTest\main.h"
#include <iostream>

class label :public QLabel {
	//Q_OBJECT
public:
	void keyPressEvent(QKeyEvent * event);
	Direction direction=Direction::right;
};