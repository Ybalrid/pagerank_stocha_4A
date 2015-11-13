#ifndef CRAWLER_H
#define CRAWLER_H

#include "pagenode.h"

class Crawler
{
public:
    Crawler();
    ~Crawler();
    void jump();
    void goToNode(PageNode* node);

signals:

public slots:
private:
    PageNode* currentNode;
};

#endif // CRAWLER_H
