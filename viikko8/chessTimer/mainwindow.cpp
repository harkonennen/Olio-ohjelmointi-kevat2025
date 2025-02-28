#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pQTimer = new QTimer(this);

    connect(ui->pushButton_Start,&QPushButton::clicked, this, &MainWindow::startHandler);
    connect(ui->pushButton_Stop,&QPushButton::clicked, this,&MainWindow::stopHandler);
    connect(ui->pushButton_5,&QPushButton::clicked, this, &MainWindow::timeHandler2);
    connect(ui->pushButton_120,&QPushButton::clicked, this, &MainWindow::timeHandler1);
    connect(ui->pushButton_Player1,&QPushButton::clicked,this, &MainWindow::switchHandler);
    connect(pQTimer,&QTimer::timeout, this, &MainWindow::timeOutHandler);

    setGameInfoText("Choose time", 12);
}

void MainWindow::startHandler()
{

    if (currentPlayer == 0 && gameTime != 0){

        pQTimer->start(1000);
        qDebug() << "Game started with" << gameTime;
        player1Time = gameTime/2;
        player2Time = gameTime/2;
        currentPlayer = 1;
        ui->progressBar_Player1->setRange(0,player1Time);
        ui->progressBar_Player2->setRange(0,player2Time);
    }
}

void MainWindow::timeout()
{
    gameTime = 0;
    player1Time = 0;
    player2Time = 0;
    currentPlayer = 0;
    pQTimer->stop();
    qDebug() << "Out of time";
    setGameInfoText("Out of time",20);
}

void MainWindow::updateProgressBar()
{
    ui->progressBar_Player1->setValue(player1Time);
    ui->progressBar_Player2->setValue(player2Time);

}

void MainWindow::checkGameOver(int winner)
{
    pQTimer->stop();

    QString winnerText = (winner == 1) ? "Player 1 Wins!" : "Player 2 Wins!";
    qDebug() << winnerText;
    setGameInfoText(winnerText, 20);

    QTimer::singleShot(3000, this, &MainWindow::resetGame);
}


void MainWindow::timeOutHandler()
{
    if (player1Time <= 0) {
        player1Time = 0;
        checkGameOver(2);
        return;
    }

    if (player2Time <= 0) {
        player2Time = 0;
        checkGameOver(1);
        return;
    }

    updateProgressBar();

    if (currentPlayer == 1) {
        player1Time--;
        setGameInfoText("Game ongoing: Player 1 turn!", 10);
    } else if (currentPlayer == 2) {
        player2Time--;
        setGameInfoText("Game ongoing: Player 2 turn!", 10);
    }
}

void MainWindow::switchHandler()
{
    if(currentPlayer == 1){
        currentPlayer = 2;

    } else if(currentPlayer == 2) {
        currentPlayer = 1;
    }
}

void MainWindow::timeHandler1()
{
    if (currentPlayer == 0 && gameTime == 0){
    gameTime = 12;
    qDebug() << "Chosen time" << gameTime;
    }
}

void MainWindow::timeHandler2()
{
    if (currentPlayer == 0 && gameTime == 0){
    gameTime = 30;
    qDebug() << "Chosen time" << gameTime;
    }
}

void MainWindow::setGameInfoText(QString s, short n)
{
    QFont font;
    font.setPointSize(n);
    ui->gameLabel->setFont(font);
    ui->gameLabel->setText(s);
}

void MainWindow::resetGame()
{
        gameTime = 0;
        player1Time = 0;
        player2Time = 0;
        currentPlayer = 0;

        setGameInfoText("Choose time", 12);
        qDebug() << "Game reset";
}

void MainWindow::stopHandler()
{
    gameTime = 0;
    currentPlayer = 0;
    player1Time = 0;
    player2Time = 0;
    pQTimer->stop();
    qDebug() << "Stopped";
    setGameInfoText("Stopped",20);
    QTimer::singleShot(3000, this, &MainWindow::resetGame);
}

MainWindow::~MainWindow()
{
    delete ui;
}
