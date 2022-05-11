#include "myitem.h"
#include <unistd.h>

int gameoverFlag = 0;
int a[8][8];
int flagNum;
extern int Click;
extern myitem *item[64];

myitem::myitem(QString path)
{
    this->setPixmap(QPixmap(path));
    IsflagOrwhiteblock = 0;
    spreadFlag = 0;
    flag = 0;
}

void myitem::setNum(int y, int x)
{
    boomNum = 0;
    if((y-1 >= 0) && (x-1 >= 0) && (a[y-1][x-1] == 1))
        boomNum++;
    if((y-1 >= 0) && a[y-1][x] == 1)
        boomNum++;
    if((y-1 >= 0) && (x+1 <= 7) && (a[y-1][x+1] == 1))
        boomNum++;
    if((x-1 >= 0) && (a[y][x-1] == 1))
        boomNum++;
    if((x+1 <= 7) && (a[y][x+1] == 1))
        boomNum++;
    if((x-1 >= 0) && (y+1 <= 7) && (a[y+1][x-1] == 1))
        boomNum++;
    if((y+1 <= 7) && (a[y+1][x] == 1))
        boomNum++;
    if((y+1 <= 7) && (x+1 <= 7) && (a[y+1][x+1] == 1))
        boomNum++;
    switch(boomNum)
    {
        case 1: item[8*y+x]->setPixmap(QPixmap(":/source_pic/11")); item[8*y+x]->IsflagOrwhiteblock += 2; break;
        case 2: item[8*y+x]->setPixmap(QPixmap(":/source_pic/22")); item[8*y+x]->IsflagOrwhiteblock += 2; break;
        case 3: item[8*y+x]->setPixmap(QPixmap(":/source_pic/33")); item[8*y+x]->IsflagOrwhiteblock += 2; break;
        case 4: item[8*y+x]->setPixmap(QPixmap(":/source_pic/44")); item[8*y+x]->IsflagOrwhiteblock += 2; break;
        case 5: item[8*y+x]->setPixmap(QPixmap(":/source_pic/55")); item[8*y+x]->IsflagOrwhiteblock += 2; break;
        case 6: item[8*y+x]->setPixmap(QPixmap(":/source_pic/66")); item[8*y+x]->IsflagOrwhiteblock += 2; break;
        case 7: item[8*y+x]->setPixmap(QPixmap(":/source_pic/77")); item[8*y+x]->IsflagOrwhiteblock += 2; break;
        case 8: item[8*y+x]->setPixmap(QPixmap(":/source_pic/88")); item[8*y+x]->IsflagOrwhiteblock += 2; break;
        case 0: item[8*y+x]->setPixmap(QPixmap(":/source_pic/f2"));
        if(y < 7 && y > 0 && x < 7 && x > 0 && item[8*y+x]->spreadFlag == 0)
        {
            item[8*y+x]->spreadFlag = 1;
            setNum(y-1, x);
            setNum(y, x-1);
            setNum(y+1, x);
            setNum(y, x+1);
        }
        if(y == 0 && (x != 0) && (x != 7) && item[8*y+x]->spreadFlag == 0)
        {
            item[8*y+x]->spreadFlag = 1;
            setNum(y, x-1);
            setNum(y+1, x);
            setNum(y, x+1);
        }
        if((x == 0) && (y != 0) && (y != 7) && item[8*y+x]->spreadFlag == 0)
        {
            item[8*y+x]->spreadFlag = 1;
            setNum(y-1, x);
            setNum(y+1, x);
            setNum(y, x+1);
        }
        if((y == 7) && (x != 0) && (x != 7) && item[8*y+x]->spreadFlag == 0)
        {
            item[8*y+x]->spreadFlag = 1;
            setNum(y-1, x);
            setNum(y, x-1);
            setNum(y, x+1);
        }
        if((x == 7) && (y != 0) && (y != 7) && item[8*y+x]->spreadFlag == 0)
        {
            item[8*y+x]->spreadFlag = 1;
            setNum(y-1, x);
            setNum(y, x-1);
            setNum(y+1, x);
        }
        if((x == 0) && (y == 0) && item[8*y+x]->spreadFlag == 0)
        {
            item[8*y+x]->spreadFlag = 1;
            setNum(y, x+1);
            setNum(y+1, x);
        }
        if((x == 7) && (y == 7) && item[8*y+x]->spreadFlag == 0)
        {
            item[8*y+x]->spreadFlag = 1;
            setNum(y-1, x);
            setNum(y, x-1);
         }
        if((y == 7) && (x == 0) && item[8*y+x]->spreadFlag == 0)
        {
            item[8*y+x]->spreadFlag = 1;
            setNum(y-1, x);
            setNum(y, x+1);
        }
        if((x == 7)&&(y == 0) && item[8*y+x]->spreadFlag == 0)
        {
            item[8*y+x]->spreadFlag = 1;
            setNum(y+1, x);
            setNum(y, x-1);
        }
        item[8*y+x]->IsflagOrwhiteblock += 2;

       break;
   }
}
void myitem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && flag == 0 && IsflagOrwhiteblock == 0)
    {
        m_x = this->pos().x();
        m_y = this->pos().y();
        setNum(m_y/48, m_x/48);

    }else if(event->button() == Qt::LeftButton && flag == 1 && IsflagOrwhiteblock == 0)
    {
        this->setPixmap(QPixmap(":/source_pic/l1"));
        gameoverFlag = 1;

    }else if(event->button() == Qt::RightButton && flag == 1)
    {
        if(IsflagOrwhiteblock == 0)
        {
            this->setPixmap(QPixmap(":/source_pic/q1"));
            IsflagOrwhiteblock++;
            flagNum++;

        }else if(IsflagOrwhiteblock == 1)
        {
            this->setPixmap(QPixmap(":/source_pic/f3"));
            IsflagOrwhiteblock--;
            flagNum--;
        }

    }else if(event->button() == Qt::RightButton && flag == 0)
    {
        if(IsflagOrwhiteblock == 0)
        {
            this->setPixmap(QPixmap(":/source_pic/q1"));
            IsflagOrwhiteblock++;
            flagNum--;
        }else if(IsflagOrwhiteblock == 1)
        {
           this->setPixmap(QPixmap(":/source_pic/f3"));
           IsflagOrwhiteblock--;
           flagNum++;
        }
    }
    /*
    else if(event->button() == Qt::MidButton && flag == 1 && IsflagOrwhiteblock == 0)
    {
        this->setPixmap(QPixmap(":/source_pic/q1"));
        flagNum++;
    }
    */
    Click++;
}
