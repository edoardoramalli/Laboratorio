#ifndef DAY_H
#define DAY_H

#include "Tempo.h"
#include "Data.h"
#include "subject.h"
#include <list>

class day: public subject{
public:

    virtual ~day();

    virtual void notify();

    virtual void registerObserver(observer* o);

    virtual void removeObserver(observer* o);

    void operator++(int);

    day operator +(int sec);

    std::string getdatetostring();

    std::string getTimetostring();

    std::string getdaytostring();

    void setDay(Tempo t,Data d);

    Data getdate();

    Tempo getTime();

    int get(){
        return temp.getSecondo();
    }

private:
    Tempo temp;
    Data myday;
    std::list<observer*> observers;
};
#endif // DAY_H
