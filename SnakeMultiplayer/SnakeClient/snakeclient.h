#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <qobject.h>
#include <qlabel.h>
//#include "snakeWithTest\main.h"
#include <iostream>
enum class Direction{left,right,up,down,stay};

class label :public QLabel {
	//Q_OBJECT
public:
	void keyPressEvent(QKeyEvent * event);
	Direction direction=Direction::right;
};
char moveSnake(Direction direction);