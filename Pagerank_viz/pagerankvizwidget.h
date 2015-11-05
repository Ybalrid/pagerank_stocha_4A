#ifndef PAGERANKVIZWIDGET_H
#define PAGERANKVIZWIDGET_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QVBoxLayout>

#include "pagegraph.h"

class PageRankVizWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PageRankVizWidget(QWidget *parent = 0);
    ~PageRankVizWidget();

signals:

public slots:
private:
    QGraphicsView* graphicsView;
    QVBoxLayout* mainLayout;
    PageGraph* pageGraph;
};

#endif // PAGERANKVIZWIDGET_H
