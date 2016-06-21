#pragma once
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <qobject.h>
#include <qlabel.h>
#include <boost\property_tree\ptree.hpp>
enum class Direction { left, right, up, down, stay };

class label :public QLabel {
	//Q_OBJECT
public:
	void keyPressEvent(QKeyEvent * event);
	Direction direction = Direction::right;
};
char moveSnake(Direction direction);
