#ifndef VISUALSORT_H
#define VISUALSORT_H

#include <QQuickPaintedItem>
#include <QObject>

//class QObject;
class BaseSort;
class VisualSort : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(Sort currentSort READ currentSort WRITE setCurrentSort NOTIFY currentSortChanged)
    Q_PROPERTY(State currentState READ currentState WRITE setCurrentState NOTIFY currentStateChanged)
public:
    enum Sort
    {
        INVALID = 0,
        BUBBLE_SORT,
        SELECTION_SORT,
    };
    Q_ENUMS(Sort)
    enum State
    {
        INVAL = 0,
        INIT,
        UN_SORTED,
        SORTING,
        SORTED
    };
    Q_ENUMS(State)
    VisualSort(QQuickPaintedItem *parent = nullptr);
    ~VisualSort();

    Q_INVOKABLE void changeState();

    Sort currentSort() const
    {
        return _currentSort;
    }
    State currentState() const
    {
        return _currentState;
    }

    void setCurrentSort(const Sort &sort);
    void setCurrentState(const State &state);

public slots:
    void onUpdateItemReceived(const int sortedIndexStart, const int sortedIndexEnd);
    void onSortingDoneReceived();

signals:
    void currentSortChanged(Sort sort);
    void currentStateChanged(State state);

protected:
    void paint(QPainter *painter);

private slots:
    void onCurrentSortChanged(Sort sortIndex);

private:
    Sort _currentSort = Sort::INVALID;
    State _currentState = State::INVAL;
    int _sortedIndexStart = -1;
    int _sortedIndexEnd = -1;
    BaseSort *_sortAlgorithm = nullptr;
    QString _stateStrings[5] = {"Invalid", "Init", "UnSorted",
                              "Sorting", "Sorted"};
};

#endif // VISUALSORT_H
