#ifndef PAGENODE_H
#define PAGENODE_H

#include <QVector>
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>

class PageNode
{
public:
    PageNode(QString accessUrl);
    void linkTo(PageNode* otherPage);
    QString getUrl();
    QGraphicsEllipseItem* getVisualNode();
    QGraphicsTextItem* getUrlTag();

    void setElipse(QGraphicsEllipseItem* e);
    void setUrlTag(QGraphicsTextItem* t);

    QVector<PageNode*> getLinkedPagesVector();

private:
    float rank;
    QVector<PageNode*> linkedPages;
    QString url;
    QGraphicsEllipseItem* elipse;
    QGraphicsTextItem* urlTag;
};

#endif // PAGENODE_H
