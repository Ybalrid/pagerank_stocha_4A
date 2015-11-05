#ifndef PAGENODE_H
#define PAGENODE_H

#include <QVector>
#include <QDebug>

class PageNode
{
public:
    PageNode(QString accessUrl);
    void linkTo(PageNode* otherPage);
    QString getUrl();
private:
    float rank;
    QVector<PageNode*> linkedPages;
    QString url;
};

#endif // PAGENODE_H
