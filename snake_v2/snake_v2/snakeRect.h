#pragma once
#include <qobject.h>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <qpoint.h>



class snakeRect :public QObject, public QGraphicsRectItem {
	Q_OBJECT
public:
	snakeRect(int x,int y,int w,int h);
	void keyPressEvent(QKeyEvent * event);
	void move();
	void add(QPoint * snakeHead);
};