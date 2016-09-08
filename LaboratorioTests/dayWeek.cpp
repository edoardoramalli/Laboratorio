//
// Created by Edoardo Ramalli on 26/07/16.
//

#include "dayWeek.h"
#include "isLeapYear.h"

std::string dayWeek(int gg, int mm, int aaaa) {
    int num=giornoSettimana(gg,mm,aaaa);
    std::string day;
    switch (num){
        case 0:
            day="Sabato";
            break;
        case 1:
            day="Domenica";
            break;
        case 2:
            day="Lundeì";
            break;
        case 3:
            day="Martedì";
            break;
        case 4:
            day="Mercoledì";
            break;
        case 5:
            day="Giovedì";
            break;
        case 6:
            day="Venerdì";
            break;
        default:
            break;
    }
    return day;
}

int giornoSettimana(int gg, int mm, int aaaa) {
    int giorno = 0;
    int x = 0;
    int t = 0;
    int mesi[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    t = mesi[mm - 1] + gg;
    bool leapyear=isLeapYear(aaaa);
    if (mm >= 3 && leapyear) {
        t++;
    }

    if (aaaa > 1582 or mm > 10 or gg > 4) {
        x = aaaa + ((aaaa - 1) / 4) - ((aaaa - 1) / 100) + ((aaaa - 1) / 400) + t;
        giorno = x % 7;
    }
    else {
        x = aaaa + (aaaa - 1) / 4 + t - 2;
        giorno = x % 7;
    }
    return giorno;
}
