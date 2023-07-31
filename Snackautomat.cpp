//
// Created by Eray Kayur on 12.07.23.
//
#include <iostream>
#include "Snackautomat.h"

Snackautomat::Snackautomat( const std::string& name, double bargeldBestand[8][2], Platz plaetze[20])
        : name(name){

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 2; j++) {
            this->bargeldBestand[i][j] = &bargeldBestand[i][j];
        }
    }


    for (int i = 0; i < 20; i++) {
        this->plaetze[i] = &plaetze[i];
    }
}

Platz* Snackautomat::warenSuchen(std::string name){
    std:: string  t;
    std:: string s;

    for (int i = 0; i < 20; i++) {
        if(plaetze[i]->getGetraenk()!= nullptr){
            t= plaetze[i]->getGetraenk()->getArtikelName();

            if( t== name){
                return plaetze[i];
            }
        }

        if(plaetze[i]->getSnack() != nullptr){
            s= plaetze[i]->getSnack()->getArtikelName();
            if( s== name){
                return plaetze[i];
            }
        }

    }
    return nullptr;
}

void Snackautomat::alleWarenAusgeben() {
    for (int i = 0; i < 20; i++) {
        if (plaetze[i]->getSnack() != nullptr) {
            std::cout << plaetze[i]->getSnack()->getArtikelName() ;
            std::cout << plaetze[i]->getSnack()->getPreis() ;
        }
        else if (plaetze[i]->getGetraenk() != nullptr) {
            std::cout << plaetze[i]->getGetraenk()->getArtikelName();
            std::cout << plaetze[i]->getGetraenk()->getPreis();
        }
        else {
            std::cout << "Kein Snack oder Getränk vorhanden";
        }

        // Führe hier weitere Operationen mit der Belegung des aktuellen Platzes aus
    }
}
Platz* Snackautomat::leerenPlatzSuchen(){
    for (int i = 0; i < 20; i++) {
        if (plaetze[i]->getSnack() ==nullptr&& plaetze[i]->getGetraenk() ==nullptr){
            return plaetze[i];

        }
    }
    return nullptr;

}