//
// Created by Eray Kayur on 11.07.23.
//

#include "Getraenk.h"


Getraenk::Getraenk(const std::string &artikelName, double preis, double pfand):Ware(artikelName, preis), pfand(pfand){}

double Getraenk::gesamtPreis() const {
    return preis + pfand;
}

double Getraenk::getPfand() const {
    return pfand;
}

void Getraenk::setPfand(double pfand) {
    Getraenk::pfand = pfand;
}



