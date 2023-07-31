//
// Created by Eray Kayur on 11.07.23.
//

#ifndef SNACKAUTOMAT_GETRAENK_H
#define SNACKAUTOMAT_GETRAENK_H

#include "Snack.h"

class Getraenk: public Ware {
private:
    double pfand;


public:
    Getraenk(const std::string &artikelName, double preis, double pfand);
//    double getPreis() const override;
 //   std::string getArtikelName() const override;
    double gesamtPreis() const override;

    double getPfand() const;

    void setPfand(double pfand);


};


#endif //SNACKAUTOMAT_GETRAENK_H
