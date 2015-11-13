#include "pagenode.h"

PageNode::PageNode(QString accessUrl) :
    url(accessUrl),
    elipse(nullptr),
    urlTag(nullptr),
    active(false),
    rank(0)
{

}

void PageNode::linkTo(PageNode *otherPage)
{
   linkedPages.push_back(otherPage);
   qDebug() << "Page " << url << " has an hyperlink to " << otherPage->getUrl();
}


QString PageNode::getUrl()
{
    return url;
}

QGraphicsEllipseItem* PageNode::getVisualNode()
{
    return elipse;
}

QGraphicsTextItem* PageNode::getUrlTag()
{
    return urlTag;
}

void PageNode::setElipse(QGraphicsEllipseItem *e)
{
    elipse = e;
}

void PageNode::setUrlTag(QGraphicsTextItem *t)
{
    urlTag = t;
}

QVector<PageNode*> PageNode::getLinkedPagesVector()
{
    return linkedPages;
}

void PageNode::setActive(bool activeState)
{
    active = activeState;
}

bool PageNode::isActive()
{
    return active;
}

void PageNode::resetRank()
{
    rank = 0;
}
void PageNode::incraseRank()
{
    rank++;
}
float PageNode::getNormalizedRank(float maxRank)
{
    return 10.0f * (rank/maxRank);
}

float PageNode::getRank()
{
    return rank;
}

