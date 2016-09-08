#ifndef OBSERVER_H
#define OBSERVER_H
class observer{
public:
    virtual ~observer(){}
    virtual void refresh()=0;
};

#endif // OBSERVER_H
