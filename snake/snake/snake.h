#pragma once
#include <QGraphicsRectItem>
#include <qobject.h>
#include <string.h>
#include <string>
#include <stdlib.h>
class snakeRect : public QObject,public QGraphicsRectItem {
Q_OBJECT
public:
	snakeRect();
	void keyPressEvent(QKeyEvent * event);
	public slots:
	void move();
	
};
class randomRect :public QGraphicsRectItem {
public:
	randomRect(){
		int x = rand()%10*10;
		int y = rand()%10*10;
		setRect(x,y, 5, 5);
	}
};
