#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include "day.h"

enum playcontrol {
    pause, stop, start
};
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    day today;
    day endtime;
    int sec_rimanenti;
    playcontrol state;
    QTimer *timer;
    QMediaPlayer *player;

    void playRing();

public slots:

    void timerevent();

private slots:

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_spinBox_2_valueChanged(int arg1);

    virtual void closeEvent(QCloseEvent *event);

    void on_toolButton_clicked();
};

#endif // MAINWINDOW_H
