#include "day.h"

day::~day(){

}

void day::registerObserver(observer* o){
    observers.push_back(o);
}
void day::removeObserver(observer *o){
    observers.remove(o);
}
void day::notify(){
    for(auto itr=std::begin(observers);itr!=end(observers);itr++){
        (*itr)->refresh();
    }
}

void day::setDay(Tempo t, Data d){
    temp=t;
    myday=d;
}

std::string day::getdatetostring(){
    return myday.display();
}

std::string day::getTimetostring(){
    return temp.display();
}
std::string day::getdaytostring(){
    return myday.display()+"   "+ temp.display();
}

Data day::getdate(){
    return myday;
}

Tempo day::getTime(){
    return temp;
}

void day::operator++(int){
    temp++;
    if(temp.getRiporto()){
        myday++;
    }
    notify();
}


day day::operator +(int sec){
    Tempo t = Tempo::secToTime(sec);
    Tempo t2=temp;
    Data d=myday;
    t2=t2+t;
    if(t2.getRiporto()){
        d++;
    }
    day my ;
    my.setDay(t2,d);
    return  my;
}
