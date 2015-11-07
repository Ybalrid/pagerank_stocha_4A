#include "pagenode.h"

PageNode::PageNode(QString accessUrl) :
    url(accessUrl),
    elipse(nullptr),
    urlTag(nullptr)

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

