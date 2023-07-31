//
// Created by Eray Kayur on 12.07.23.
//
#include "Ware.h"

Ware::Ware(const std::string& artikelName, double preis) { // & um auf den string zu referenzierend
    this->artikelName = artikelName;
    this->preis = preis;
}


const std::string &Ware::getArtikelName() const {
    return artikelName;
}

void Ware::setArtikelName(const std::string &artikelName) {
    Ware::artikelName = artikelName;
}

double Ware::getPreis() const {
    return preis;
}

void Ware::setPreis(double preis) {
    Ware::preis = preis;
}
