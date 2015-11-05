#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Configure main window display
    setWindowTitle("Pagerank - Visualisation");
    setMinimumSize(1024, 768);


}

MainWindow::~MainWindow()
{

}
