#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <QObject>
#include <QThread>

class VisualSort;
class SelectionSort : public QThread
{
    Q_OBJECT
public:
    explicit SelectionSort(QObject *parent = nullptr);
    ~SelectionSort();

    void setItem(VisualSort *item);
    void init(const int &size, const int &max);

    int *_data = nullptr;

protected:
    void run();

signals:
    void updateItem();

private:
    int _size = 0;
    VisualSort *_item = nullptr;

    void sort();
    inline void swap(const int &a, const int &b, int *arr);

};

#endif // SELECTIONSORT_H
