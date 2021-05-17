#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString scaner;
    QTimer *timer;
    bool scanner_start;
    int scaner_num;

private slots:
    void timeOut();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_clicked();

protected:
   virtual void keyPressEvent(QKeyEvent *event);
   virtual void keyReleaseEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
