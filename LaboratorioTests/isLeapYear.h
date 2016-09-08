//
// Created by Edoardo Ramalli on 26/07/16.
//

#ifndef LABORSTORIO_ISLEAPYEAR_H
#define LABORSTORIO_ISLEAPYEAR_H

bool isLeapYear(int year){
    if(year!=0){
        return ((year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0));
    }
    return true;
}

#endif //LABORSTORIO_ISLEAPYEAR_H
