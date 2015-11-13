#include "pagerankvizwidget.h"

PageRankVizWidget::PageRankVizWidget(QWidget *parent) : QWidget(parent)
{
    graphicsView = new QGraphicsView(this);
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(graphicsView);
    setLayout(mainLayout);

    pageGraph = new PageGraph;
    graphicsView->setScene(pageGraph->getGraphicsScene());
    pageGraph->recomputeGraphicsScene();
    timer = new QTimer(this);

    timer->setInterval(10);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(doDebugStep()));
    QObject::connect(this, SIGNAL(allIterationDone()), this, SLOT(writeResultsToDebug()));
    QObject::connect(this, SIGNAL(allIterationDone()), this, SLOT(displayResult()));
}

PageRankVizWidget::~PageRankVizWidget()
{
    //delete pageGraph;
}


void PageRankVizWidget::exploreGraph()
{
    //qDebug() << "Explore graph triggered";
    ExploreParam* ep = new ExploreParam(this);
    ep->show();
    qDebug() << "ep show done";
    //timer->start();
    QObject::connect(ep, SIGNAL(startExplore(int,int,int)), this, SLOT(startExplore(int,int,int)));
}

void PageRankVizWidget::startExplore(int time, int nbCrawl, int maxIter)
{
    timer->setInterval(time);
    pageGraph->createCrawlers(nbCrawl);
    timer->start();
    step = maxIter;
}

void PageRankVizWidget::resetGraph()
{
    qDebug() << "Reset graph triggered";
    timer->stop();
    pageGraph->clearCrawlers();
    pageGraph->resetRank();
    this->repaint();
}
void PageRankVizWidget::paintEvent(QPaintEvent* e)
{
    //qDebug() << "Paint Event!!";
    pageGraph->recomputeGraphicsScene();
    QWidget::paintEvent(e);
}

void PageRankVizWidget::doDebugStep()
{
    if(step <= 0)
    {
        timer->stop();
        emit allIterationDone();
    }
    pageGraph->debugStep();
    this->repaint();
    step--;
    qDebug() << step;
}

void PageRankVizWidget::writeResultsToDebug()
{
    //pageGraph->writeStatusToDebug();
}

bool moreThan( PageNode*& a,  PageNode*& b)
{
    return a->getRank() > b->getRank();
}

void PageRankVizWidget::displayResult()
{
    float max = pageGraph->getMaxRank();
    auto index = pageGraph->getIndex();
    qSort(index.begin(), index.end(), moreThan);

    std::stringstream ss;

    for(auto page : index)
    {
        qDebug() << page->getNormalizedRank(max) << " : " << page->getUrl();
        ss << page->getNormalizedRank(max) << " : " << page->getUrl().toStdString() << std::endl;
    }

    QTextEdit *resultWindow = new QTextEdit;
    resultWindow->setText(ss.str().c_str());
    resultWindow->setWindowTitle("Result");
    resultWindow->setReadOnly(true);
    resultWindow->show();

}
