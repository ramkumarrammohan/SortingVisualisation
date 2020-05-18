#include "selectionsort.h"
#include <QDebug>
#include "visualsort.h"

SelectionSort::SelectionSort(QObject *parent) : QThread(parent)
{

}

SelectionSort::~SelectionSort()
{
    delete _data;
}

void SelectionSort::setItem(VisualSort *item)
{
    _item = item;
}

void SelectionSort::init(const int &size, const int &max)
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

void SelectionSort::run()
{
    this->sort();
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
        emit updateItem();
        msleep(5);
    }
}

void SelectionSort::swap(const int &a, const int &b, int *arr)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
