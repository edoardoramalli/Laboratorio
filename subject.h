#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"
class subject{
public:
    virtual void registerObserver(observer* o)=0;
    virtual void removeObserver(observer* o)=0;
    virtual void notify()=0;
protected:
    virtual ~subject(){};

};

#endif // SUBJECT_H
