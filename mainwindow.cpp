#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QMessageBox>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {

    ui->setupUi(this);


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerevent()));
    timer->start(1000);
    ui->bar->connect(&today);
    ui->lcdNumber->connect(&today);
    state = stop;


}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::timerevent() {
    today++;
    if (state == start) {
        sec_rimanenti--;
        ui->bar->setValue(sec_rimanenti);
        Tempo t = Tempo::secToTime(sec_rimanenti);
        std::string text = t.display();
        ui->bar->setFormat(QString::fromStdString(text));
        if (sec_rimanenti == 0) {
            if (ui->lineEdit->text() != "") {
                playRing();
            }
            QMessageBox msgBox;
            msgBox.setText("Timer");
            msgBox.setInformativeText("The timer is finished");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            int ret = msgBox.exec();
            switch (ret) {
                case QMessageBox::Ok:
                    player->stop();
                    break;
                default:
                    break;
            }
            ui->bar->disconnect();
            state = stop;
            ui->pushButton_2->setText("PAUSE");
            ui->bar->connect(&today);
            ui->pushButton->setDisabled(false);
            ui->pushButton_2->setDisabled(true);
            ui->spinBox->setValue(0);
            ui->spinBox_2->setValue(0);
            ui->label_3->setText("");
        }
    }
    else if (state == pause) {
        endtime++;
        ui->label_3->setText(QString::fromStdString("END: " + endtime.getdaytostring()));

    }
    ui->label->setText(QString::fromStdString(today.getdatetostring()));

}

void MainWindow::on_spinBox_valueChanged(int arg1) {
    if (ui->spinBox->value() == 60) {
        ui->spinBox->setValue(0);
    }
    if (ui->spinBox->value() == -1) {
        ui->spinBox->setValue(59);
    }
    if (ui->spinBox->value() != 0 or ui->spinBox_2->value() != 0) {
        ui->pushButton->setDisabled(false);
    }
    else {
        ui->pushButton->setDisabled(true);
    }

}

void MainWindow::on_pushButton_clicked() {
    if (state == stop) {
        sec_rimanenti = ui->spinBox->value() * 60 + ui->spinBox_2->value() * 3600;
        endtime = today + sec_rimanenti;
        ui->bar->setNullPosition(-90);
        ui->bar->disconnect();
        ui->bar->setRange(0, sec_rimanenti);


    }
    else if (state == pause) {
        ui->pushButton_2->setText("PAUSE");
    }
    ui->pushButton->setDisabled(true);
    ui->pushButton_2->setDisabled(false);
    ui->label_3->setText(QString::fromStdString("END: " + endtime.getdaytostring()));
    state = start;


}

void MainWindow::on_pushButton_2_clicked() {
    if (state == pause) {
        ui->bar->disconnect();
        state = stop;
        ui->pushButton_2->setText("PAUSE");
        ui->bar->connect(&today);
        ui->pushButton->setDisabled(false);
        ui->pushButton_2->setDisabled(true);
        ui->spinBox->setValue(0);
        ui->spinBox_2->setValue(0);
        ui->label_3->setText("");
    }
    else {
        state = pause;
        ui->pushButton->setDisabled(false);
        ui->pushButton_2->setText("STOP");
    }
}


void MainWindow::on_spinBox_2_valueChanged(int arg1) {
    if (ui->spinBox_2->value() == 24) {
        ui->spinBox_2->setValue(0);
    }
    if (ui->spinBox_2->value() == -1) {
        ui->spinBox_2->setValue(23);
    }
    if (ui->spinBox->value() != 0 or ui->spinBox_2->value() != 0) {
        ui->pushButton->setDisabled(false);
    }
    else {
        ui->pushButton->setDisabled(true);
    }

}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (state == start or state == pause) {
        QMessageBox::warning(this, "Timer", "The timer is not finished");
    }
    ui->bar->disconnect();
    ui->lcdNumber->disconnect();
    timer->stop();
}

void MainWindow::playRing() {
    player = new QMediaPlayer;
    try {
        player->setMedia(QUrl::fromLocalFile(ui->lineEdit->text()));
        player->setVolume(100);
        player->play();
    }
    catch (...) {
        QMessageBox::critical(this, "Timer", "Error Media Player");
    }
}

void MainWindow::on_toolButton_clicked() {
    QString url = "";
    url = QFileDialog::getOpenFileName(this, "Edit Url of the ring", QDir::homePath(), "Audio Files *.*");
    if (url != "") {
        ui->lineEdit->setText(url);
    }
}
