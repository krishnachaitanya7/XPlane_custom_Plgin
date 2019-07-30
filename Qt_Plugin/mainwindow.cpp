#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QtWidgets/QGridLayout>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createFirstQuestion(), 0, 0);
    grid->addWidget(createSecondQuestion(), 1, 0);
    setLayout(grid);

    setWindowTitle(tr("Group Boxes"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
QGroupBox *MainWindow::createFirstQuestion() {
    QGroupBox *groupBox = new QGroupBox(tr("Did you enjoy XPlane experience?"));

    QRadioButton *radio1 = new QRadioButton(tr("Yes"));
    QRadioButton *radio2 = new QRadioButton(tr("No"));
    QRadioButton *radio3 = new QRadioButton(tr("Maybe"));
    QRadioButton *radio4 = new QRadioButton(tr("God Knows"));

    radio1->setChecked(true);
}
