#include "snakeclientGUI.h"

void label::keyPressEvent(QKeyEvent * event) {
	if (event->key() == Qt::Key_Up) {
		direction = Direction::up;
	}
	if (event->key() == Qt::Key_Down) {
		direction = Direction::down;
	}
	if (event->key() == Qt::Key_Left) {
		direction = Direction::left;
	}
	if (event->key() == Qt::Key_Right) {
		direction = Direction::right;
	}
	if (event->key() == Qt::Key_Insert) {
		direction == Direction::newGame;
	}
}
char moveSnake(Direction direction) {
	//direction is converted in it's index as string to be sent
	switch (direction) {
	case Direction::left:
		return '0';
	case Direction::right:
		return '1';
	case Direction::up:
		return '2';
	case Direction::down:
		return '3';
	case Direction::newGame:
		return 'n';
	default:
		return '4';
	}
}

