#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "basesort.h"

class SelectionSort : public BaseSort
{
    Q_OBJECT
public:
    explicit SelectionSort(QObject *parent = nullptr);
    ~SelectionSort();

    void sort() override;

};

#endif // SELECTIONSORT_H
