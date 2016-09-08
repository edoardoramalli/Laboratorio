#include "lcdclock.h"


LcdClock::LcdClock(QWidget *parent) :
        QLCDNumber(parent) {

    this->setDigitCount(30);
}

LcdClock::~LcdClock() {
    subject->removeObserver(this);

}

void LcdClock::connect(day *s) {
    subject = s;
    subject->registerObserver(this);
}

void LcdClock::refresh() {
    t = subject->getTime();
    mydata = subject->getdate();
    std::string text = "";
    int temp = t.getOra();
    if (temp < 10) {
        text = "0" + std::to_string(temp) + ":";
    }
    else {
        text = std::to_string(temp) + ":";
    }
    temp = t.getMinuto();
    if (temp < 10) {
        text = text + "0" + std::to_string(temp) + ":";
    }
    else {
        text = text + std::to_string(temp) + ":";
    }
    temp = t.getSecondo();
    if (temp < 10) {
        text = text + "0" + std::to_string(temp);
    }
    else {
        text = text + std::to_string(temp);
    }
    text = mydata.display() + " " + text;
    this->display(QString::fromStdString(text));
}
