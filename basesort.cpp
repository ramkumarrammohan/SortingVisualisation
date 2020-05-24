#include "basesort.h"
#include <QDebug>

BaseSort::BaseSort(QObject *parent) : QThread(parent)
{
    qDebug() << Q_FUNC_INFO;
}

BaseSort::~BaseSort()
{
    qDebug() << Q_FUNC_INFO;
    if (_data)
        delete _data;
}

void BaseSort::initArray(const int &size, const int &max)
{
    if (size <=0 || max <= 0 || _data != nullptr)
    {
        qWarning() << "initArray failed";
        return;
    }

    _data = new int[size];
    _size = size;
    for (int i = 0; i < size; i++)
    {
        _data[i] = qrand() % max;
    }
    emit updateItem(-1, -1);
}

void BaseSort::run()
{
    this->sort();
}

void BaseSort::swap(const int &a, const int &b, int *arr)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
