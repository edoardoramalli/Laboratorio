//
// Created by Edoardo Ramalli on 26/07/16.
//

#include "Data.h"
#include <ctime>
#include "isLeapYear.h"
#include "dayWeek.cpp"
#include <string>



Data::Data(int g, int m, int a,Format f) {
    leapyear=isLeapYear(a);
    anno=a;
    if (m<1 or m>12){
        mese=1;
    }
    else {
        mese = m;
    }
    bool error=false;
    if(g<1 or g>31){
        giorno=1;
        error=true;
    }
    if(!error){
        switch (mese) {
            case 1:
                giorno = g;
                break;
            case 2:
                if (!leapyear) {
                    if (g > 28) {
                        giorno = 1;
                    }
                }
                else {
                    if (g > 29)
                        giorno = 1;

                    else {
                        giorno = g;
                    }
                }
                break;
            case 3:
                giorno=g;
                break;
            case 4:
                if(g>30){
                    g=1;
                }
                else{
                    giorno=g;
                }
            case 5:
                giorno=g;
                break;
            case 6:
                if(g>30){
                    g=1;
                }
                else{
                    giorno=g;
                }
            case 7:
                giorno=g;
                break;
            case 8:
                giorno=g;
                break;
            case 9:
                if(g>30){
                    g=1;
                }
                else{
                    giorno=g;
                }
            case 10:
                giorno=g;
                break;
            case 11:
                if(g>30){
                    g=1;
                }
                else{
                    giorno=g;
                }
            case 12:
                giorno=g;
                break;
            default:
                break;

        }
    }
    dayofweek=dayWeek(g,m,a);
    format=f;
}

Data::Data() {
    std::time_t t = std::time(nullptr);
    struct tm *time;
    time = localtime(&t);
    giorno=time->tm_mday;
    mese=(time->tm_mon)+1;
    anno=(time->tm_year)+1900;
    dayofweek=dayWeek(giorno,mese,anno);
    leapyear=isLeapYear(anno);
    format=EUlong;
}

std::string Data::display() {
    std::string output="";
      if(format==EUlong){
          output= dayofweek+", "+std::to_string(giorno)+" "+nameOfMounth()+" "+std::to_string(anno);
      }
      else if (format==EUshort){
           output= std::to_string(giorno)+"/"+std::to_string(mese)+"/"+std::to_string(anno);
      }
      else if (format==USAlong){
           output= dayofweek+", "+nameOfMounth()+" "+std::to_string(giorno)+", "+std::to_string(anno);
      }
      else if (format==USAshort){
           output= std::to_string(mese)+"/"+std::to_string(giorno)+"/"+std::to_string(anno);
      }
      return output;
}

std::string Data::nameOfMounth() {
    int num=this->mese;
    std::string name="";
    switch(num){
        case 1:
            name="Gennaio";
            break;
        case 2:
            name="Febbraio";
            break;
        case 3:
            name="Marzo";
            break;
        case 4:
            name="Aprile";
            break;
        case 5:
            name="Maggio";
            break;
        case 6:
            name="Giugno";
            break;
        case 7:
            name="Luglio";
            break;
        case 8:
            name="Agosto";
            break;
        case 9:
            name="Settembre";
            break;
        case 10:
            name="Ottobre";
            break;
        case 11:
            name="Novembre";
            break;
        case 12:
            name="Dicembre";
            break;
        default:
            break;
    }
    return name;
}

void Data::setDay(int gg, int mm, int aaaa, Format f) {
    int day=gg;
    int mounth=mm;
    format=f;
    anno=aaaa;
    leapyear=isLeapYear(anno);
    controlDate(day,mounth);
    giorno=day;
    mese=mounth;
    dayofweek=dayWeek(giorno,mese,anno);
}

void Data::controlDate(int& gg,int &mm) {
    if (mm < 1 or mm > 12) {
        mm = 1;
    }
    bool error = false;
    if (gg < 1 or gg > 31) {
        gg = 1;
        error = true;
    }
    if (!error) {
        switch (mm) {
            case 1:
                break;
            case 2:
                if (!leapyear) {
                    if (gg > 28) {
                        gg= 1;
                    }
                }
                else {
                    if (gg > 29)
                        gg = 1;
                }
                break;
            case 3:
                break;
            case 4:
                if (gg > 30) {
                    gg = 1;
                }
            case 5:
                break;
            case 6:
                if (gg > 30) {
                    gg = 1;
                }
            case 7:
                break;
            case 8:
                break;
            case 9:
                if (gg > 30) {
                    gg = 1;
                }
            case 10:
                break;
            case 11:
                if (gg > 30) {
                    gg = 1;
                }
            case 12:
                break;
            default:
                break;

        }
    }
}

int Data::operator-(const Data &right) const {
    int difference=0;
    Data magg;
    Data min;
    if(*this<=right){
        min=*this;
        magg=right;
    }
    else{
        min=right;
        magg=*this;
    }
    int fromyearmag=magg.dayFromYear();
    int fromyearmin=min.dayFromYear();

    if(magg.anno==min.anno){
        difference=fromyearmag-fromyearmin;
    }
    else{
        for(int i=min.anno;i!=magg.anno;i++){
            if(isLeapYear(i)){
                difference+=366;
            }
            else{
                difference+=365;
            }
        }
        difference=difference-fromyearmin+fromyearmag ;
    }
    return difference;
}

bool Data::operator<=(const Data &right) const {

    if(anno<=right.anno && mese<=right.mese && giorno<=right.giorno){
        return true;
    }
    return false;
}

Data& Data::operator++(int){
    giorno++;
    if(mese==2){
        if (leapyear){
            if(giorno>29){
                giorno=giorno%29;
                mese++;
            }
        }
        else{
            if(giorno>28){
                giorno=giorno%28;
                mese++;
            }
        }
    }
    if(mese==1 or mese==3 or mese==5 or mese==7 or mese==8 or mese==19 or mese==12){
        if(giorno>31){
            giorno=giorno%31;
            mese++;
        }
    }
    if (mese==4 or mese==6 or mese==9 or mese==11){
        if(giorno>30){
            giorno=giorno%30;
            mese++;
        }
    }
    if(mese>12){
        mese=mese%12;
        anno++;
    }

    leapyear=isLeapyear();
    dayofweek=dayWeek(giorno,mese,anno);
    return *this;
}

int Data::dayFromYear()const {
    int mesi[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int days=0;
    days=mesi[mese-1]+giorno;
    if(isLeapyear()and mese>2 and giorno>=1){
        days++;
    }
    return days;
}
