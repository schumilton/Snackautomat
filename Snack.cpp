//
// Created by Eray Kayur on 11.07.23.
//

#include "Snack.h"

Snack::Snack(const std::string &artikelName, double preis) : Ware(artikelName, preis) {}

double Snack::gesamtPreis() const {
    return preis ;
}
