#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    ~MainWindow();
    void mekanik();

private slots:
    void handleClick();
    void resetClick();

private:
    Ui::MainWindow *ui;
    int counter = 0;
    int resetCounter = 0;
};
#endif // MAINWINDOW_H
