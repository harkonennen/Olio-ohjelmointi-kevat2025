#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->count,&QPushButton::clicked,this,&MainWindow::handleClick);
    connect(ui->reset,&QPushButton::clicked,this,&MainWindow::resetClick);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mekanik()
{

}

void MainWindow::handleClick()
{
    counter++;
    QString teksti = QString::number(counter);
    ui->teksti->setText(teksti);
    if (resetCounter != 0) ui->reset->setText(teksti);
}

void MainWindow::resetClick()
{
    counter = 0;
    resetCounter++;
    QString teksti = QString::number(counter);
    ui->reset->setText(teksti);
}


