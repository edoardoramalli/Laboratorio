//
// Created by Edoardo Ramalli on 24/07/16.
//

#include "Tempo.h"
#include <ctime>
#include <iostream>
#include <string>


Tempo::Tempo() {
    std::time_t t = std::time(nullptr);
    struct tm *time;
    time = localtime(&t);
    format = full24;
    meridian = empty;
    ora = time->tm_hour;
    minuto = time->tm_min;
    secondo = time->tm_sec;
}

Tempo::Tempo(int o, int m, int s, TimeFormat f, Meridian meridiann) {

    if (f == full24 or f == small24) {

        if (o < 0 or o > 23) {
            ora = 0;
        }
        else {
            ora = o;
        }

    }
    else {
        if (o < 1 or o > 12)
            ora = 12;
        else {
            ora = o;
        }

    }
    if (m < 0 or m > 59) {
        minuto = 0;
    } else {
        minuto = m;
    }
    if (s < 0 or s > 59) {
        secondo = 0;
    }
    else {
        secondo = s;
    }

    format = f;

    Tempo::meridian = meridiann;
}

void Tempo::setTime(int h, int min, int sec,Meridian mer) {
    if (this->format == full24 or this->format == small24) {

        if (h < 0 or h > 23) {
            ora = 0;
        }
        else {
            ora = h;
        }

    }
    else {
        if (h < 1 or h > 12)
            ora = 12;
        else {
            ora = h;
        }
        this->meridian=mer;
    }
    if (min < 0 or min > 59) {
        minuto = 0;
    } else {
        minuto = min;
    }
    if (sec < 0 or sec > 59) {
        secondo = 0;
    }
    else {
        secondo = sec;
    }
}

void Tempo::setFormat(TimeFormat f) {
    if ((Tempo::format == full24 or Tempo::format == small24) and (f == small12 or f == full12)) {
        if (ora >= 12) {
            meridian = PM;
            if(ora!=12){
                ora = ora % 12;
            }

        }
        else {
            meridian = AM;
            if (ora == 0) {
                ora = 12;
            }
        }
        Tempo::format = f;
    }
    else if ((Tempo::format == full12 or Tempo::format == small12) and (f == small24 or f == full24)) {
        if (meridian == AM) {
            if (ora == 12) {
                ora = 0;
            }
        }
        else {
            if (ora == 12) {
                ora = 0;
            }
            ora = (ora + 12);
        }
        meridian = empty;
        Tempo::format = f;
    }
}

Tempo& Tempo::operator+(const Tempo &right)const {

    static Tempo risultato(0, 0, 0, full24);
    Tempo addendo1=*this;
    Tempo addendo2=right;
    TimeFormat sx = this->format;
    TimeFormat dx = right.format;

    addendo1.setFormat(full24);
    addendo2.setFormat(full24);

    int sec = addendo2.secondo + addendo1.secondo;
    int resto = 0;
    if (sec >= 60) {
        if ((sec % 60) != 0) {
            sec = sec % 60;
            resto = 1;
        }
    }
    risultato.secondo = sec;

    int min = resto + addendo1.minuto + addendo2.minuto;
    resto = 0;
    if (min >= 60) {
        if ((min % 60) != 0) {
            min = min % 60;
            resto = 1;
        }
    }
    risultato.minuto = min;

    int ora = resto + addendo1.ora + addendo2.ora;

    if (ora >= 24) {
        if ((ora % 24 != 0)) {
            ora = ora % 24;
            resto=1;
        }
    }
    risultato.ora = ora;
    risultato.riporto=resto;


    addendo2.setFormat(sx);
    addendo1.setFormat(dx);

    return risultato;

}

Tempo& Tempo::operator++(int){
    int resto=0;
    riporto=false;
    secondo++;
    if (secondo>=60){
        secondo=secondo%60;
        resto=1;
    }
    minuto=minuto+resto;
    resto=0;
    if(minuto>=60){
        resto=1;
        minuto=minuto%60;
    }
    ora=ora+resto;
    resto=0;
    if(ora>=24){
        ora=ora%60;
        resto=1;
        riporto=resto;
    }
    return *this;
}

bool Tempo::operator ==(const Tempo& right)const{
    Tempo f1 =*this;
    Tempo f2 =right;
    bool same=false;
    if(f1.getFormat()!=full24){

        f1.setFormat(full24);
    }
    if(f2.getFormat()!=full24){

        f2.setFormat(full24);
    }
    if(f1.getSecondo()==f2.getSecondo() and f1.getMinuto()==f2.getMinuto() and f1.getOra()==f2.getOra()){
        same=true;
    }
    else{
        same=false;
    }

    return same;
}

Tempo Tempo::secToTime(int sec){
   int hh,mm,ss;
   ss = sec % 60;
   sec= (sec - ss) / 60;
   mm =sec % 60;
   sec = (sec - mm) / 60;
   hh = sec % 24;
   Tempo temp(hh,mm,ss,full24);
   return temp;

}

std::string Tempo::display() {
    std::string f,output;
    if (meridian != empty and meridian == AM) {
        f = "AM";
    }
    else
        f = "PM";
    std::string hh,mm,ss;
    if(ora<10){
        hh="0"+std::to_string(ora);
    }
    else{
        hh=std::to_string(ora);
    }
    if(minuto<10){
        mm="0"+std::to_string(minuto);
    }
    else{
        mm=std::to_string(minuto);
    }

    if(secondo<10){
        ss="0"+std::to_string(secondo);
    }
    else{
        ss=std::to_string(secondo);
    }
    if (format == small24) {
        output=hh+" : " +mm ;
    }
    else if (format == full24) {
        output=hh + " : " + mm + " : " + ss;
    }
    else if (format == small12) {
        output=hh + " : " + mm + " " + f ;
    }
    else if (format == full12) {
        output=hh + " : " + mm +  " : " + ss + " " + f ;
    }
    return output;
}

