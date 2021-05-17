#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(timeOut()));
    scanner_start = true;
    scaner_num = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    /*
    QString oldText;
    int key = event->key();//event->key() - целочисленный код клавиши
    QString str = QString(QChar(key));
    scaner += str;
    qDebug() << str << key;

    if(!scanner_start)timer->start(1000);
    scanner_start++;*/
/*
    if (event->isAutoRepeat())
        {
            return;
        }

        if (!event->isAutoRepeat())
        {
            qDebug() << "[MainWindow::keyPressEvent()] " << event->key() << "; " << event->isAutoRepeat();
        }

        */
}

void MainWindow::timeOut()
{
    timer->stop();
    if(scaner_num > 4) qDebug() << scaner;
    scaner.clear();
    scaner_num = 0;
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(!scanner_start) return;
    if (event->isAutoRepeat()) return;
    scaner_num++;
    int key = event->key();
    timer->start(50);
    QString str = QString(QChar(key));
    scaner += str;
    qDebug() << str << key;
}
