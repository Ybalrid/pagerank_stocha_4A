#ifndef PAGEGRAPH_H
#define PAGEGRAPH_H

#include <ctime>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "pagenode.h"
#include "crawler.h"
#define SCALE 10
#define NBCRAWL 4

///Graph created by the index of pages known by the engine
class PageGraph
{
public:
    PageGraph();
    ~PageGraph();
    QGraphicsScene* getGraphicsScene();

    ///
    /// \brief getFromUrl
    /// \param url
    /// \return page node from that url, or nullptr if this url is not indexed
    ///
    PageNode* getFromUrl(QString url);
    ///
    /// \brief recomputeGraphicsScene replace the nodes on the graph.\
    /// the distribution has been fixed by defining a fixed seed to the RNG
    ///
    void recomputeGraphicsScene();

    ///
    /// \brief createCrawlers create all crawlers you want
    /// \param nbCrawl
    ///
    void createCrawlers(int nbCrawl);
    ///
    /// \brief clearCrawlers Remove all crawlers
    ///
    void clearCrawlers();
    ///
    /// \brief debugStep step the simulation
    ///
    void debugStep();
    ///
    /// \brief resetRank put everything back to 0
    ///
    void resetRank();
    ///
    /// \brief writeStatusToDebug write to qDebug() the current status of the ranks
    ///
    void writeStatusToDebug();

    float getMaxRank();

    ///Get the array of known nodes
    QVector<PageNode*> getIndex();

private:


    ///
    /// \brief createDummyGraph create a graph of 16 pages
    ///
    void createDummyGraph();
    QVector<PageNode*> indexedPages;
    QGraphicsScene* graphicsScene;
    QPen pen;
    QBrush brush;
    QBrush activeBrush;

    QVector<Crawler*> crawlers;

};

#endif // PAGEGRAPH_H
