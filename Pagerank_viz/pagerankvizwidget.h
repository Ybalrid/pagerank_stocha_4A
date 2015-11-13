#ifndef PAGERANKVIZWIDGET_H
#define PAGERANKVIZWIDGET_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QPaintEvent>
#include <QTimer>
#include <QTextEdit>

#include <sstream>

#include "pagegraph.h"
#include "exploreparam.h"


class PageRankVizWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PageRankVizWidget(QWidget *parent = 0);
    ~PageRankVizWidget();
    virtual void paintEvent(QPaintEvent* e);

signals:
    void allIterationDone();

public slots:
    void resetGraph();
    void exploreGraph();
    void startExplore(int time, int nbCrawl, int maxIter);
    void doDebugStep();
    void writeResultsToDebug();
    void displayResult();
private:
    QGraphicsView* graphicsView;
    QVBoxLayout* mainLayout;
    PageGraph* pageGraph;
    int step;

    //-------debug
    QTimer* timer;
};

#endif // PAGERANKVIZWIDGET_H
