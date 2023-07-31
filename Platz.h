//
// Created by Eray Kayur on 12.07.23.
//

#ifndef SNACKAUTOMAT_PLATZ_H
#define SNACKAUTOMAT_PLATZ_H
#include "Getraenk.h"
#include "Snack.h"

class Platz {
private:
    int menge;
    Getraenk* getraenk;
    Snack* snack;
public:
    int getMenge() const;

    void setMenge(int menge);

    Getraenk *getGetraenk() const;

    void setGetraenk(Getraenk *getraenk);

    Snack *getSnack() const;

    void setSnack(Snack *snack);

public:
    Platz();
    bool auffuellen(int anzahl);
    bool entnehmen(int  anzahl);

};


#endif //SNACKAUTOMAT_PLATZ_H
