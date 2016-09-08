//
// Created by Edoardo Ramalli on 24/07/16.
//

#ifndef LABORSTORIO_TEMPO_H
#define LABORSTORIO_TEMPO_H
#include <string>
enum TimeFormat {
    full24, small24, full12, small12
};
enum Meridian {
    AM, PM, empty
};

class Tempo {
public:
    Tempo();

    Tempo(int o, int m, int s, TimeFormat f, Meridian meridiann = empty);

    Tempo& operator+(const Tempo &right)const;

    Tempo& operator++(int);

    bool operator ==(const Tempo &right)const;

    std::string display();

    void setFormat(TimeFormat f);

    void setTime(int h, int min, int sec,Meridian mer =empty);

    static Tempo secToTime(int sec);

    const Meridian &getMeridian() const {
        return meridian;
    }

    const TimeFormat &getFormat() const {
        return format;
    }

    int getOra() const {
        return ora;
    }

    int getSecondo() const {
        return secondo;
    }

    int getMinuto() const {
        return minuto;
    }

    bool getRiporto() const {
        return riporto;
    }

private:
    int minuto, secondo, ora;
    TimeFormat format;
    Meridian meridian;
    bool riporto;
};


#endif //LABORSTORIO_TEMPO_H
