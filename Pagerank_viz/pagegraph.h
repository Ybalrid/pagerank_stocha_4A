#ifndef PAGEGRAPH_H
#define PAGEGRAPH_H

#include <ctime>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "pagenode.h"
#include "crawler.h"
#define SCALE 10
#define NBCRAWL 4

class PageGraph
{
public:
    PageGraph();
    ~PageGraph();
    QGraphicsScene* getGraphicsScene();
    PageNode* getFromUrl(QString url);
    void recomputeGraphicsScene();

    void createCrawlers(int nbCrawl);
    void clearCrawlers();
    void debugStep();
    void resetRank();

    void writeStatusToDebug();

    float getMaxRank();
    QVector<PageNode*> getIndex();

private:
    void createDummyGraph();
    QVector<PageNode*> indexedPages;
    QGraphicsScene* graphicsScene;
    QPen pen;
    QBrush brush;
    QBrush activeBrush;

    QVector<Crawler*> crawlers;

};

#endif // PAGEGRAPH_H
