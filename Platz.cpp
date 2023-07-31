//
// Created by Eray Kayur on 12.07.23.
//

#include "Platz.h"

Platz::Platz() : menge(menge), getraenk(nullptr), snack(nullptr) {}


bool Platz::auffuellen(int anzahl){

}
bool Platz::entnehmen(int anzahl) {

    if(menge >= anzahl){
        menge= menge - anzahl;
        if(menge==0){
            getraenk = nullptr;
            snack= nullptr;
        }
        return true;
    }
    else{
        return false;
    }

}

int Platz::getMenge() const {
    return menge;
}

void Platz::setMenge(int menge) {
    Platz::menge = menge;
}
// gibt pointer zu getraenk zurück
Getraenk *Platz::getGetraenk() const {
    return getraenk;
}

void Platz::setGetraenk(Getraenk *getraenk) {
    Platz::getraenk = getraenk;
}

Snack *Platz::getSnack() const {
    return snack;
}

void Platz::setSnack(Snack *snack) {
    Platz::snack = snack;
}
