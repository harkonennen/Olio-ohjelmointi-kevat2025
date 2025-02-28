#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void timeout();
    void updateProgressBar();
    void setGameInfoText(QString, short);
    void resetGame();
    void checkGameOver(int);
    ~MainWindow();

private slots:
    void timeOutHandler();
    void startHandler();
    void stopHandler();
    void switchHandler();
    void timeHandler1();
    void timeHandler2();

private:
    Ui::MainWindow *ui;
    short player1Time;
    short player2Time;
    short currentPlayer = 0;
    short gameTime = 0;

    QTimer * pQTimer;
};
#endif // MAINWINDOW_H
