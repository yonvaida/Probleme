#ifndef SNAKE_V2_H
#define SNAKE_V2_H

#include <QtWidgets/QMainWindow>
#include "ui_snake_v2.h"

class snake_v2 : public QMainWindow
{
	Q_OBJECT

public:
	snake_v2(QWidget *parent = 0);
	~snake_v2();

private:
	Ui::snake_v2Class ui;
};

#endif // SNAKE_V2_H
