#pragma once
#include <QKeyEvent>
#include <qobject.h>
#include <qlabel.h>

enum class Direction { left, right, up, down, stay,newGame };

class label :public QLabel {
public:
	void keyPressEvent(QKeyEvent * event);
	Direction direction = Direction::right;
};
char moveSnake(Direction direction);
