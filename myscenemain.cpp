#include "myscenemain.h"

myscenemain::myscenemain(QObject *parent) : QGraphicsScene(parent)
{
    QString path="://source_pic/source_1";
    itemmain = new myitemmain(path);
    this->addItem(itemmain);
}
