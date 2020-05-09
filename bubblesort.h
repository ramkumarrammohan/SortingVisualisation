#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <QObject>
#include <QThread>

class VisualSort;
class BubbleSort : public QThread
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);
    ~BubbleSort();

    void setItem(VisualSort *item);
    void init(const int &size, const int &max);
    void run();

    int *_data = nullptr;

signals:
    void updateItem();

private:
    int _size = 0;
    VisualSort *_item = nullptr;

    void sort();
    inline void swap(const int &a, const int &b, int *arr);
};

#endif // BUBBLESORT_H
