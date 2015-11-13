#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include "pagerankvizwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    PageRankVizWidget* pageRankViz;
    QAction* exploreGraphAction;
    QAction* quitAction;
    QAction* resetAction;
};

#endif // MAINWINDOW_H
