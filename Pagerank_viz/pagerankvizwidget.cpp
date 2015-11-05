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
}

PageRankVizWidget::~PageRankVizWidget()
{
    //delete pageGraph;
}



