#ifndef BASESORT_H
#define BASESORT_H

#define SLEEP 100

#include <QThread>

class BaseSort : public QThread
{
    Q_OBJECT
public:
    explicit BaseSort(QObject *parent = nullptr);
    virtual ~BaseSort();

    void initArray(const int &size, const int &max);
    int* data()
    {
        return _data;
    }
    int size()
    {
        return _size;
    }

protected:
    void run();
    void swap(const int &a, const int &b, int *arr);

    int *_data = nullptr;
    int _size = 0;

signals:
    void updateItem(const int sortedIndexStart, const int sortedIndexEnd);
    void sortingDone();

private:
    virtual void sort() = 0;
};

#endif // BASESORT_H
