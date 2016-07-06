#include "snakegui.h"
#include <QtWidgets/QApplication>
#include <memory>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	std::unique_ptr<QGraphicsScene> scene(new QGraphicsScene());
	std::unique_ptr<QGraphicsView> view(new QGraphicsView(scene.get()));

	view->show();
	return a.exec();
}
