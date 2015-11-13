#include "exploreparam.h"

ExploreParam::ExploreParam(QWidget *parent) : QDialog(parent),
    timeInterval(10),
    nbCrawler(3),
    maxIterate(50)
{
    setModal(true);
    setFixedWidth(350);
    setWindowTitle("Exploration parameters");

    timeSpinBox         = new QSpinBox(this);
    nbCrawlerSpinBox    = new QSpinBox(this);
    maxIterateSpinBox   = new QSpinBox(this);

    timeSpinBox->setMaximum(1000);
    nbCrawlerSpinBox->setMaximum(5);
    maxIterateSpinBox->setMaximum(1000);

    maxIterateSpinBox->setValue(maxIterate);
    timeSpinBox->setValue(timeInterval);
    nbCrawlerSpinBox->setValue(nbCrawler);

    formLayout = new QFormLayout;
    formLayout->addRow("Time beween intervals (ms)", timeSpinBox);
    formLayout->addRow("Number of crawlers", nbCrawlerSpinBox);
    formLayout->addRow("Max iteration", maxIterateSpinBox);


    okButton = new QPushButton("Ok");
    cancelButton = new QPushButton("Cancel");

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    QObject::connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(reject()));
    QObject::connect(okButton, SIGNAL(clicked(bool)), this, SLOT(accept()));

}

void ExploreParam::accept()
{
    emit startExplore(timeSpinBox->value(), nbCrawlerSpinBox->value(), maxIterateSpinBox->value());
    QDialog::accept();
}

