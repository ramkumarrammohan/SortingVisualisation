#include "visualsort.h"
#include "bubblesort.h"
#include "selectionsort.h"

#include <QPainter>

#define SPACING 10
#define SORTED_COLOR "#80DEEA"
#define UNSORTED_COLOR "#9FA8DA"
#define PRIMARY_COLOR "#4db6ac"
#define SECONDARY_COLOR "#00796b"

VisualSort::VisualSort(QQuickPaintedItem *parent) :
    QQuickPaintedItem(parent)
{
    connect(this, SIGNAL(widthChanged()), this, SLOT(update()));
    connect(this, &VisualSort::currentSortChanged, this, &VisualSort::onCurrentSortChanged);
    qDebug() << "constr";
    changeState();
}

VisualSort::~VisualSort()
{
    qDebug() << Q_FUNC_INFO;
    if(_sortAlgorithm)
        delete _sortAlgorithm;
}

void VisualSort::paint(QPainter *painter)
{
    if (!painter)
        return;

    painter->setPen(QPen(SECONDARY_COLOR));
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawRect(this->boundingRect());

    if (_currentState == State::INVAL || _currentState == State::INIT)
        return;

    if (_sortAlgorithm->size() <= 0)
        return;

    QPen penSorted(QColor(SORTED_COLOR), SPACING/2);
    QPen penUnSorted(QColor(UNSORTED_COLOR), SPACING/2);

    qDebug() << QString("start,end: %1,%2").arg(_sortedIndexStart).arg(_sortedIndexEnd);
    for(int i = 0; i < this->width() / SPACING; i++)
    {
        if (i >= _sortedIndexStart && i < _sortedIndexEnd)
        {
            painter->setPen(penSorted);
        } else
        {
            painter->setPen(penUnSorted);
        }

        painter->drawLine(i * SPACING, this->height(), i * SPACING, _sortAlgorithm->data()[i]);
    }
}

void VisualSort::onCurrentSortChanged(VisualSort::Sort sortIndex)
{
    qDebug() << "sortindex: " << sortIndex;
    if(_sortAlgorithm != nullptr)
        delete _sortAlgorithm;

    if (sortIndex == Sort::BUBBLE_SORT)
    {
       _sortAlgorithm = new BubbleSort;
    } else if (sortIndex == Sort::SELECTION_SORT)
    {
        _sortAlgorithm = new SelectionSort;
    } else
    {
        qWarning() << "unknown sort type received";
    }
    connect(_sortAlgorithm, SIGNAL(updateItem(int, int)), this, SLOT(onUpdateItemReceived(int, int)), Qt::QueuedConnection);
    connect(_sortAlgorithm, SIGNAL(sortingDone()), this, SLOT(onSortingDoneReceived()), Qt::QueuedConnection);
    setCurrentState(State::INIT);
}

void VisualSort::changeState()
{
    QString entry = _stateStrings[_currentState];
    switch (_currentState) {
    case State::INVAL:
        setCurrentState(State::INIT);
        break;
    case State::INIT:
    {
        int size = this->width() / SPACING;
        int max = this->height();
        _sortAlgorithm->initArray(size, max);
        setCurrentState(State::UN_SORTED);
    }
        break;
    case State::UN_SORTED:
    {
        _sortAlgorithm->start();
        setCurrentState(State::SORTING);
    }
        break;
    case State::SORTING:
        setCurrentState(State::SORTED);
        break;
    case State::SORTED:
        setCurrentState(State::INIT);
        break;
    default:
        qWarning() << Q_FUNC_INFO << " unhandled state: " << _currentState;
        break;
    }
//    qDebug() << QString("(entry, exit): (%1, %2)").arg(entry).arg(_stateStrings[_currentState]);
}

void VisualSort::setCurrentSort(const VisualSort::Sort &sort)
{
    if (_currentSort == sort || sort == Sort::INVALID)
        return;
    _currentSort = sort;
    emit currentSortChanged(sort);
}

void VisualSort::setCurrentState(const VisualSort::State &state)
{
    if (_currentState == state || state == State::INVAL)
        return;
    _currentState = state;
    emit currentStateChanged(state);
}

void VisualSort::onUpdateItemReceived(const int sortedIndexStart, const int sortedIndexEnd)
{
    _sortedIndexStart = sortedIndexStart;
    _sortedIndexEnd = sortedIndexEnd;
    this->update();
}

void VisualSort::onSortingDoneReceived()
{
    changeState();
}
