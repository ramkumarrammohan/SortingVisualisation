#ifndef VISUALSORT_H
#define VISUALSORT_H

#include <QQuickPaintedItem>
#include <QObject>

//class QObject;
class BubbleSort;
class SelectionSort;
class VisualSort : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(bool init READ init WRITE setInit NOTIFY initChanged)
public:
    VisualSort(QQuickPaintedItem *parent = nullptr);

    Q_INVOKABLE void start();
    Q_INVOKABLE void drawCall();

    bool init() const
    {
        return _init;
    }

    void setInit(const bool &value);

signals:
    void initChanged(bool init);

protected:
    void paint(QPainter *painter);

private:
    bool _init = false;
    BubbleSort *_sortalgo = nullptr;
    SelectionSort *_selectionSort = nullptr;
};

#endif // VISUALSORT_H
