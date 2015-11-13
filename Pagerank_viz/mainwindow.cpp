#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Configure main window display
    setWindowTitle("Pagerank - Visualisation");
    setMinimumSize(600, 480);

    setCentralWidget(pageRankViz = new PageRankVizWidget(this));
    QToolBar* toolbar = addToolBar("ToolBar");
    exploreGraphAction =toolbar->addAction("Explore Graph");
    resetAction = toolbar->addAction("Reset");
    quitAction = toolbar->addAction("Quit");

}

MainWindow::~MainWindow()
{

}
