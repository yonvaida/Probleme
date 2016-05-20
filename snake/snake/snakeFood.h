#pragma once
#include <qgraphicsitem.h>
#include <QGraphicsRectItem>
#include <stdlib.h>

class randomRect :public QGraphicsRectItem {
public:
	randomRect() {
		setRect(rand() % 10 * 10, rand() % 10 * 10, 5, 5);
	}
};
