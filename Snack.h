//
// Created by Eray Kayur on 11.07.23.
//
#pragma once
#ifndef SNACKAUTOMAT_SNACK_H
#define SNACKAUTOMAT_SNACK_H

#endif //SNACKAUTOMAT_SNACK_H
#include "Ware.h"

class Snack: public Ware{


public:
    Snack(const std::string &artikelName, double preis);
    double gesamtPreis() const override;

};