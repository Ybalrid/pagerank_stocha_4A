#ifndef EXPLOREPARAM_H
#define EXPLOREPARAM_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QPushButton>

class ExploreParam : public QDialog
{
    Q_OBJECT
public:
    explicit ExploreParam(QWidget *parent = 0);


signals:
    void startExplore(int time, int nbcrawl, int maxIterate);
public slots:
    virtual void accept();
private:
    int timeInterval;
    int nbCrawler;
    int maxIterate;

    QVBoxLayout* mainLayout;
    QFormLayout* formLayout;

    QSpinBox* timeSpinBox;
    QSpinBox* nbCrawlerSpinBox;
    QSpinBox* maxIterateSpinBox;
    QPushButton* okButton;
    QPushButton* cancelButton;


};

#endif // EXPLOREPARAM_H
