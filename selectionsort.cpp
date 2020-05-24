#include "selectionsort.h"
#include <QDebug>

SelectionSort::SelectionSort(QObject *parent) : BaseSort(parent)
{
    qDebug() << Q_FUNC_INFO;
}

SelectionSort::~SelectionSort()
{
    qDebug() << Q_FUNC_INFO;
}

void SelectionSort::sort()
{
    qDebug() << Q_FUNC_INFO;
    int sortedIndex = 0;
    int minIndex = 0;
    while (sortedIndex < _size)
    {
        minIndex = sortedIndex;
        for (int i = sortedIndex; i < _size; i++)
        {
            if (_data[i] > _data[minIndex])
                minIndex = i;
        }
        swap(minIndex, sortedIndex, _data);
        sortedIndex++;
        msleep(SLEEP);
        emit updateItem(-1, sortedIndex);
    }
    emit sortingDone();
}
