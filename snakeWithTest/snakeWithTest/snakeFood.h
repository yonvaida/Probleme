#pragma once
#include <qapplication.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <QGraphicsRectItem>
#include <memory>

class snakeGUI {
	
public:
	snakeGUI() {};
int startGUI(int argc, char *argv[]);
void addRectangle(int x, int y);
private:
	
	std::unique_ptr<QGraphicsScene> scene;
	std::unique_ptr<QGraphicsView> view;
};
