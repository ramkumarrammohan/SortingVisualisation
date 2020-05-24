#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "basesort.h"

class BubbleSort : public BaseSort
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);
    ~BubbleSort();

    void sort() override;
};

#endif // BUBBLESORT_H
