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

///Widget that contains the drawn graph
class PageRankVizWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PageRankVizWidget(QWidget *parent = 0);
    ~PageRankVizWidget();
    ///overload paint event to refresh the graphics view each time it's needed.
    virtual void paintEvent(QPaintEvent* e);

signals:
    ///
    /// \brief allIterationDone
    ///simulation is done
    void allIterationDone();

public slots:
    ///
    /// \brief resetGraph
    ///reset the graph
    void resetGraph();
    ///
    /// \brief exploreGraph
    ///launch the graph exploration. open the parameters dialog
    void exploreGraph();
    ///
    /// \brief startExplore
    /// \param time time interval in milliseconds between 2 step++
    /// \param nbCrawl number of crawlers on the graph (<= 5)
    /// \param maxIter max number of iteration
    ///effectively start the simulation
    void startExplore(int time, int nbCrawl, int maxIter);
    ///
    /// \brief doDebugStep
    ///Do the steps
    void doDebugStep();
    ///
    /// \brief writeResultsToDebug
    ///call the debug write. (write the result of simulation to qDebug()
    void writeResultsToDebug();
    ///
    /// \brief displayResult
    ///open a dialog with a textarea containing the result of the simulation as plain text
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
