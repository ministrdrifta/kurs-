#ifndef MYITEM_H
#define MYITEM_H
#include<QString>
#include<QGraphicsPixmapItem>
#include<QGraphicsSceneMouseEvent>
#include<QMessageBox>
#include<QDebug>

class myitem : public QGraphicsPixmapItem
{
public:
    myitem(QString path);
    int flag;
    void setNum(int y, int x);
private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    int boomNum;
    int IsflagOrwhiteblock;
    int spreadFlag;
    int m_x;
    int m_y;
};

#endif // MYITEM_H
