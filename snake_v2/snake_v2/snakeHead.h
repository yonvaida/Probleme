#pragma once
#include <qobject.h>
#include <QGraphicsRectItem>
#include <QKeyEvent>



class snakeHeadRect :public QObject, public QGraphicsRectItem {
	Q_OBJECT
public:
	snakeHeadRect(int x,int y,int w,int h);
	void keyPressEvent(QKeyEvent * event);
	void move();
};