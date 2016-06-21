#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <qobject.h>
#include <qlabel.h>
//#include "snakeWithTest\main.h"
#include <iostream>
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\json_parser.hpp>
#include <string>
enum class Direction{left,right,up,down,stay};

class label :public QLabel {
	//Q_OBJECT
public:
	void keyPressEvent(QKeyEvent * event);
	Direction direction=Direction::right;
};
char moveSnake(Direction direction);

void convertToPtree(std::string bufferValue, boost::property_tree::ptree &data);