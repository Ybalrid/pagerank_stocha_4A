#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Configure main window display
    setWindowTitle("Pagerank - Visualisation");
    setMinimumSize(600, 480);

    setCentralWidget(pageRankViz = new PageRankVizWidget(this));
    QToolBar* toolbar = addToolBar("ToolBar");
//    exploreGraphAction =toolbar->addAction("Explore Graph");
//    resetAction = toolbar->addAction("Reset");
//    quitAction = toolbar->addAction("Quit");

    exploreGraphAction = new QAction("Explore Graph", this);
    resetAction = new QAction("Reset", this);
    quitAction = new QAction("Quit", this);

    toolbar->addAction(exploreGraphAction);
    toolbar->addAction(resetAction);
    toolbar->addAction(quitAction);

    QObject::connect(exploreGraphAction, SIGNAL(triggered(bool)), pageRankViz, SLOT(exploreGraph()));
    QObject::connect(resetAction, SIGNAL(triggered(bool)), pageRankViz, SLOT(resetGraph()));
    QObject::connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{

}
