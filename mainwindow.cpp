#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>
#include <QTextCodec>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(timeOut()));
    scanner_start = true;
    scaner_num = 0;
    QByteArray f;
    f.append("685778 HS X2-W/200W");
    qDebug() << f.size();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

}

void MainWindow::timeOut()
{
    timer->stop();
    if(scaner_num >= 8) qDebug() << scaner;
    if(scaner == "685778 HS X2-W/200W") qDebug() << "ura";
    ui->lineEdit->setReadOnly(true);
    scaner.clear();
    scaner_num = 0;
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(!scanner_start) return;
    if (event->isAutoRepeat()) return;
    scaner_num++;
    //int key = event->key();
    int key = event->nativeVirtualKey();
    QString dd = event->text();

    timer->start(100);
    QString str;
    if(key >= 33) str = QString(QChar(key));
    if(str == "?") qDebug() << "=?";
    scaner += str;
    qDebug() << str << key;
    //ui->lineEdit->setReadOnly(true);
    //ui->lineEdit->setReadOnly(false);

}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}

void MainWindow::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text();
    qDebug() << text;
}
