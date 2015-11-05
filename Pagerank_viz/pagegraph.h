#ifndef PAGEGRAPH_H
#define PAGEGRAPH_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "pagenode.h"
#define SCALE 10

class PageGraph
{
public:
    PageGraph();
    QGraphicsScene* getGraphicsScene();
    PageNode* getFromUrl(QString url);
    void recomputeGraphicsScene();

private:
    void createDummyGraph();
    QVector<PageNode*> indexedPages;
    QGraphicsScene* graphicsScene;
    QPen pen;
    QBrush brush;
};

#endif // PAGEGRAPH_H
