#include "pagenode.h"

PageNode::PageNode(QString accessUrl) :
    url(accessUrl)

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
