#ifndef LCDCLOCK_H
#define LCDCLOCK_H

#include <QLCDNumber>
#include "observer.h"
#include "day.h"

namespace Ui {
class LcdClock;
}

class LcdClock : public QLCDNumber, public observer
{
    Q_OBJECT

public:
    explicit LcdClock(QWidget *parent = 0);
    ~LcdClock();
    void refresh();
    void connect(day* s);

private:
    Ui::LcdClock *ui;
    day* subject;
    Tempo t;
    Data mydata;
};

#endif // LCDCLOCK_H
