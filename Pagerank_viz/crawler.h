#ifndef CRAWLER_H
#define CRAWLER_H

#include "pagenode.h"

///A crawler represent a "googlebot" that will explore the graph created by the indexed pages
class Crawler
{
public:
    Crawler();
    ~Crawler();

    ///jumps to a page linked to currentNode at random.
    void jump();

    ///Go to a specific node
    void goToNode(PageNode* node);

signals:

public slots:
private:
    PageNode* currentNode;
};

#endif // CRAWLER_H
