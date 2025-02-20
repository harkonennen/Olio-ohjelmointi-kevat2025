#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Connects to set up buttons and their functions
    connect(ui->add,&QPushButton::clicked,this,MainWindow::addSubMulDivClickHandler);
    connect(ui->div,&QPushButton::clicked,this,MainWindow::addSubMulDivClickHandler);
    connect(ui->mul,&QPushButton::clicked,this,MainWindow::addSubMulDivClickHandler);
    connect(ui->sub,&QPushButton::clicked,this,MainWindow::addSubMulDivClickHandler);

    connect(ui->clear,&QPushButton::clicked,this,MainWindow::clearClickHandler);
    connect(ui->enter,&QPushButton::clicked,this,MainWindow::enterClickHandler);

    connect(ui->n0,&QPushButton::clicked,this,MainWindow::numberClickedHandler);
    connect(ui->n1,&QPushButton::clicked,this,MainWindow::numberClickedHandler);
    connect(ui->n2,&QPushButton::clicked,this,MainWindow::numberClickedHandler);
    connect(ui->n3,&QPushButton::clicked,this,MainWindow::numberClickedHandler);
    connect(ui->n4,&QPushButton::clicked,this,MainWindow::numberClickedHandler);
    connect(ui->n5,&QPushButton::clicked,this,MainWindow::numberClickedHandler);
    connect(ui->n6,&QPushButton::clicked,this,MainWindow::numberClickedHandler);
    connect(ui->n7,&QPushButton::clicked,this,MainWindow::numberClickedHandler);
    connect(ui->n8,&QPushButton::clicked,this,MainWindow::numberClickedHandler);
    connect(ui->n9,&QPushButton::clicked,this,MainWindow::numberClickedHandler);

    // Set state to 1 for debug
    state = 1;
    qDebug()<<state;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickedHandler()
{
    //Get sender object and place to *button
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    //Set name
    QString numberName = button->objectName();
    qDebug() << "Button name: " << numberName.at(1);

    //Find out which number we are taking in by looking at states
    if(state == 1){
        //Take previous text and add new button press to it
        ui->num1Line->setText(ui->num1Line->text()+numberName.at(1));
        //save inputted numbers in num1Line to number 1
        number1 = ui->num1Line->text();

        //Same as above
    }   else if (state == 2){
        ui->num2Line->setText(ui->num2Line->text()+numberName.at(1));
        number2 = ui->num2Line->text();
    }
}

void MainWindow::enterClickHandler()
{
        qDebug() << "Enter";
        //Covert number1 and 2 to float
        float n1 = number1.toFloat();
        float n2 = number2.toFloat();
        qDebug() << n1 << n2;

        //Calculate numbers depending on given operator
        switch (operand){
            case 0:
                result = n1 + n2;
                break;

            case 1:
                result = n1 - n2;
                break;

            case 2:
                result = n1 * n2;
                break;

            case 3:
                result = n1 / n2;
                break;
        }
        //Show result at resultLine
        ui->resultLine->setText(QString::number(result));
}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    //Set name
    QString operandName = button->objectName();
    qDebug() << "Button name: " << operandName;

    state = 2;

    //Save wanted operator as a number
    if(operandName == "add"){
        operand = 0;
        ui->operandLine->setText("+");

    } else if (operandName == "sub"){
        operand = 1;
        ui->operandLine->setText("-");

    } else if (operandName == "mul"){
        operand = 2;
        ui->operandLine->setText("*");

    } else if(operandName == "div"){
        operand = 3;
        ui->operandLine->setText("/");
    }
}

void MainWindow::clearClickHandler()
{
    //Clear everything
    state = 1;
    number1 = "";
    number2 = "";
    ui->num1Line->setText("");
    ui->num2Line->setText("");
    ui->operandLine->setText("");
    ui->resultLine->setText("");

    //Debug
    qDebug()<< "Clear" << state << number1 << number2;
}
