#include "bubblesort.h"
#include <QDebug>
#include "visualsort.h"

BubbleSort::BubbleSort(QObject *parent) : QThread(parent)
{

}

BubbleSort::~BubbleSort()
{
    delete _data;
}

void BubbleSort::setItem(VisualSort *item)
{
    _item = item;
}

void BubbleSort::sort()
{
    qDebug() << Q_FUNC_INFO;
    for(int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size - i - 1; j++)
        {
            if (_data[j] > _data[j+1])
            {
                swap(j, j+1, _data);
            }
        }
        emit updateItem();
        msleep(5);
    }
}

void BubbleSort::run()
{
    this->sort();
}

void BubbleSort::init(const int &size, const int &max)
{
    qDebug() << Q_FUNC_INFO;
    if (size <=0 || max <= 0)
        return;

    _data = new int[size];
    _size = size;
    for (int i = 0; i < size; i++)
    {
        _data[i] = qrand() % max;
    }
    QMetaObject::invokeMethod(_item, "drawCall");
}

void BubbleSort::swap(const int &a, const int &b, int *arr)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
