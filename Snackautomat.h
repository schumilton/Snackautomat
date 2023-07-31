//
// Created by Eray Kayur on 12.07.23.
//

#ifndef SNACKAUTOMAT_SNACKAUTOMAT_H
#define SNACKAUTOMAT_SNACKAUTOMAT_H
#include <string>
#include "Platz.h"

class Snackautomat {
private:
    std::string name;
    double*bargeldBestand[8][2];
    Platz* plaetze[20];

public:
    Snackautomat( const std::string &name, double bargeldBestand[8][2],Platz plaetze[20]);
    Platz* warenSuchen(std::string name);
    Platz* leerenPlatzSuchen();
    void alleWarenAusgeben();

};


#endif //SNACKAUTOMAT_SNACKAUTOMAT_H
