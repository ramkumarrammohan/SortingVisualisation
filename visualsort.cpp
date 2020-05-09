#include "visualsort.h"
#include "bubblesort.h"

#include <QPainter>
#include <QThread>

//#define PRIMARY_COLOR "#1de9b6"
//#define SECONDARY_COLOR "#00bfa5"

#define PRIMARY_COLOR "#4db6ac"
#define SECONDARY_COLOR "#00796b"

VisualSort::VisualSort(QQuickPaintedItem *parent) :
    QQuickPaintedItem(parent)
{
    _sortalgo = new BubbleSort;
    connect(_sortalgo, SIGNAL(updateItem()), this, SLOT(update()), Qt::QueuedConnection);
}

void VisualSort::paint(QPainter *painter)
{
    if (!painter)
        return;

    painter->setPen(QPen(SECONDARY_COLOR));
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawRect(this->boundingRect());

    if (!_init)
        return;

    QPen pen(QColor(SECONDARY_COLOR));
    painter->setPen(pen);
    for(int i = 0; i < this->width(); i++)
    {
        painter->drawLine(i, this->height(), i, _sortalgo->_data[i]);
    }
}

void VisualSort::start()
{
    if (!_init)
    {
        int size = this->width();
        int max = this->height();
        _sortalgo->setItem(this);
        _sortalgo->init(size, max);
        setInit(true);
    } else
    {
        _sortalgo->start();
    }
}

void VisualSort::drawCall()
{
    this->update();
}

void VisualSort::setInit(const bool &value)
{
    if (_init == value)
        return;
    _init = value;
    emit initChanged(value);
}
