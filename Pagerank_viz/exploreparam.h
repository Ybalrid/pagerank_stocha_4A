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

///Dialog box to get the exploration parameters
class ExploreParam : public QDialog
{
    Q_OBJECT
public:
    explicit ExploreParam(QWidget *parent = 0);


signals:
    ///Signal emited when parameters are known
    void startExplore(int time, int nbcrawl, int maxIterate);
public slots:
    ///Slots attached to the "ok" button on the dialog
    virtual void accept();
private:
    int timeInterval;
    int nbCrawler;
    int maxIterate;

    QVBoxLayout* mainLayout;
    QFormLayout* formLayout;

    ///Man Machine Interface content
    QSpinBox* timeSpinBox;
    QSpinBox* nbCrawlerSpinBox;
    QSpinBox* maxIterateSpinBox;
    QPushButton* okButton;
    QPushButton* cancelButton;


};

#endif // EXPLOREPARAM_H
