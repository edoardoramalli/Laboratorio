//
// Created by Edoardo Ramalli on 26/07/16.
//

#ifndef LABORSTORIO_DATA_H
#define LABORSTORIO_DATA_H

#include <string>

enum Format {
    USAshort, USAlong, EUshort, EUlong
};

class Data {
public:
    Data();

    Data(int gg, int mm, int aaaa, Format f);

    std::string display();

    void setDay(int gg, int mm, int aaaa, Format f);

    int operator-(const Data& right)const;

    bool operator<=(const Data& right)const;

    Data& operator++(int);

    int getGiorno() const {
        return giorno;
    }

    int getMese() const {
        return mese;
    }

    int getAnno() const {
        return anno;
    }

    bool isLeapyear() const {
        return leapyear;
    }

    const Format &getFormat() const {
        return format;
    }

    const std::string &getDayofweek() const {
        return dayofweek;
    }

private:
    int giorno, mese, anno;
    bool leapyear;
    Format format;
    std::string dayofweek;
private:
    std::string nameOfMounth();

    void controlDate(int &gg, int &mm);

    int dayFromYear()const;
};


#endif //LABORSTORIO_DATA_H
