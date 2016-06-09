#include "snakerender.h"
void label::keyPressEvent(QKeyEvent * event) {
	if (event->key() == Qt::Key_Up) {
		direction = Direction::up;
		//std::cout << "up" << std::endl;
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

}