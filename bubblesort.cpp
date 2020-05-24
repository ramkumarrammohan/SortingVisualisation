#include "bubblesort.h"
#include <QDebug>

BubbleSort::BubbleSort(QObject *parent) : BaseSort(parent)
{
    qDebug() << Q_FUNC_INFO;
}

BubbleSort::~BubbleSort()
{
    qDebug() << Q_FUNC_INFO;
}

void BubbleSort::sort()
{
    qDebug() << Q_FUNC_INFO;
    for(int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size - i - 1; j++)
        {
            if (_data[j] < _data[j+1])
            {
                swap(j, j+1, _data);
            }
        }
        msleep(SLEEP);
        emit updateItem(_size - i, _size);
    }
    emit sortingDone();
}
