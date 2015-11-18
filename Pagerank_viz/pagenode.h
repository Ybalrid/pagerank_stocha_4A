#ifndef PAGENODE_H
#define PAGENODE_H

#include <QVector>
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>

///A graph node that represent a page on the index
class PageNode
{
public:
    PageNode(QString accessUrl);

    ///
    /// \brief linkTo
    /// \param otherPage
    ///Add a link to another page
    void linkTo(PageNode* otherPage);
    ///
    /// \brief getUrl
    /// \return
    ///get the URL
    QString getUrl();

    ///
    /// \brief getVisualNode
    /// \return
    ///get the graphical representation
    QGraphicsEllipseItem* getVisualNode();

    ///
    /// \brief getUrlTag
    /// \return
    ///get the text tag attached to the node
    QGraphicsTextItem* getUrlTag();

    ///
    /// \brief setElipse
    /// \param e
    /// set the elipse item from the graph' scene
    void setElipse(QGraphicsEllipseItem* e);
    ///
    /// \brief setUrlTag
    /// \param t
    ///set the name tag from the graph scene
    void setUrlTag(QGraphicsTextItem* t);

    ///
    /// \brief getLinkedPagesVector
    /// \return
    ///get the list of links between this page and another one
    QVector<PageNode*> getLinkedPagesVector();

    ///
    /// \brief setActive
    /// \param activeState
    ///Set the node as active
    void setActive(bool activeState = true);
    ///
    /// \brief isActive
    /// \return state of the node
    ///
    bool isActive();
    ///
    /// \brief resetRank
    ///Reset the rank to zero
    void resetRank();

    ///
    /// \brief incraseRank
    ///rank++
    void incraseRank();

    ///
    /// \brief getRank
    /// \return
    ///get absolute rank value
    float getRank();

    ///
    /// \brief getNormalizedRank
    /// \param maxRank max absolute rank (that will be = to 10.0f)
    /// \return computed rank
    ///get the pagerank scoce on a 0.0f -> 10.0f scale
    float getNormalizedRank(float maxRank);

private:
    float rank;
    QVector<PageNode*> linkedPages;
    QString url;
    QGraphicsEllipseItem* elipse;
    QGraphicsTextItem* urlTag;
    bool active;
};

#endif // PAGENODE_H
