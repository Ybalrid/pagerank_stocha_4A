#include "pagegraph.h"

PageGraph::PageGraph():
    brush(QBrush(Qt::red))
{

    //Qt Graphics:
    graphicsScene = new QGraphicsScene;

    createDummyGraph();
    pen.setWidth(5);

}

QGraphicsScene* PageGraph::getGraphicsScene()
{
    return graphicsScene;
}

void PageGraph::createDummyGraph()
{
    for(int i = 0; i < 15; i++)
    {
        QString url(QString("http://page") + ('A' + i) + QString(".com/index.html"));
        indexedPages.push_back(new PageNode(url));
    }

    for(int i = 0; i < 15 - 3; i++)
    {
        indexedPages[i]->linkTo(indexedPages[i+1]);
        indexedPages[i+1]->linkTo(indexedPages[i+2]);
        indexedPages[i+2]->linkTo(indexedPages[i]);
    }
}

PageNode* PageGraph::getFromUrl(QString url)
{
    for(int i(0); i < indexedPages.size(); i++)
        if(indexedPages[i]->getUrl() == url)
            return indexedPages[i];
    return nullptr;
}

void PageGraph::recomputeGraphicsScene()
{
    graphicsScene->clear();
    for(int i(0); i < indexedPages.size(); i++)
    {
        int x, y, w, h;
        w=h=5*SCALE;

        if(i < indexedPages.size()/2)
        {
            y = 10*SCALE;
            x = 15*SCALE*i;
        }
        else
        {
            y = -10*SCALE;
            x = 15*SCALE*(i - indexedPages.size()/2);
        }

        QGraphicsEllipseItem* elipse = graphicsScene->addEllipse(x,y,w,h,pen,brush);
        QGraphicsTextItem* url = graphicsScene->addText(indexedPages[i]->getUrl());
        url->setPos(x-10,y-20);
    }
}
