#include "crawler.h"

Crawler::Crawler() :
    currentNode(nullptr)
{
}

Crawler::~Crawler()
{
    if(currentNode) currentNode->setActive(false);
}

void Crawler::jump()
{
   if(!currentNode) return;
   QVector<PageNode*>& linkList = currentNode->getLinkedPagesVector();
   int listSize = linkList.size();

   int jumpIndex = rand() % listSize;
   if(linkList[jumpIndex] != currentNode)
    goToNode(linkList[jumpIndex]);
}

void Crawler::goToNode(PageNode* node)
{
    //qDebug() << "jump!!";
    if(currentNode) currentNode->setActive(false);
    currentNode = nullptr;
    if(!node) return;
    currentNode = node;
    currentNode->setActive();
    currentNode->incraseRank();
}
