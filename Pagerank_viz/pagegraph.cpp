#include "pagegraph.h"

PageGraph::PageGraph():
    brush(QBrush(Qt::red))
{

    //Qt Graphics:
    graphicsScene = new QGraphicsScene;

    createDummyGraph();
    pen.setWidth(3);

}

QGraphicsScene* PageGraph::getGraphicsScene()
{
    return graphicsScene;
}

void PageGraph::createDummyGraph()
{
    const unsigned int nb = 16;
    for(int i = 0; i < nb; i++)
    {
        QString url(QString("http://page") + ('A' + i) + QString(".com/"));
        indexedPages.push_back(new PageNode(url));
    }

    for(int i = 0; i < nb; i++)
    {
        for(int j(0); j < 1 + rand() % 2 ; j++)
        indexedPages[i]->linkTo(indexedPages[rand()%nb]);
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
    //Clean up what's curently on the scene
    graphicsScene->clear();

    //Create visual representation of each known node in the system
    for(int i(0); i < indexedPages.size(); i++)
    {
        int x, y, w, h;
        w=h=5*SCALE;

        if(i < indexedPages.size()/2 )
        {
            y = -10*SCALE;
            x = 15*SCALE*i;
        }
        else
        {
            y = 10*SCALE;
            x = 15*SCALE*(i - indexedPages.size()/2);
        }

        x += -5 + rand() % 10*SCALE;
        y += -5 + rand() % 10*SCALE;


        QGraphicsEllipseItem* elipse = graphicsScene->addEllipse(x,y,w,h,pen,brush);
        QGraphicsTextItem* url = graphicsScene->addText(indexedPages[i]->getUrl());
        url->setPos(x-10,y-20);

        indexedPages[i]->setElipse(elipse);
        indexedPages[i]->setUrlTag(url);
    }

    for(int i(0); i < indexedPages.size(); i++)
    {
        PageNode* page = indexedPages[i];
        QRectF r =page->getVisualNode()->rect();
        QPointF pos(r.x(), r.y());
        pos += QPointF(r.width()/2, r.height()/2);



        for(int j(0); j < page->getLinkedPagesVector().size(); j++)
        {
            QRectF r =  page->getLinkedPagesVector()[j]->getVisualNode()->rect();
            QPointF endPos(r.x(), r.y());
            endPos += QPointF(r.width()/2, r.height()/2);

            graphicsScene->addLine(QLineF(pos,endPos));
            qDebug() << "Draw a line between " << pos << " and " << endPos;
            if(endPos.x() > pos.x())
                graphicsScene->addLine(QLineF(endPos, endPos - QPointF(SCALE,0)), pen);
            else
                graphicsScene->addLine(QLineF(endPos, endPos + QPointF(SCALE,0)), pen);

            if(endPos.y() > pos.y())
                graphicsScene->addLine(QLineF(endPos, endPos - QPointF(0,SCALE)), pen);
            else
                graphicsScene->addLine(QLineF(endPos, endPos + QPointF(0,SCALE)), pen);
        }
    }
}
