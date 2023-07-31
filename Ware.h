//
// Created by Eray Kayur on 11.07.23.
//
#pragma once
#ifndef SNACKAUTOMAT_WARE_H
#define SNACKAUTOMAT_WARE_H

#endif //SNACKAUTOMAT_WARE_H
#include <string>

class Ware {
protected:
    std::string artikelName;
    double preis;
public:
    Ware(const std::string& artikelName, double preis);

    const std::string &getArtikelName() const;

    void setArtikelName(const std::string &artikelName);

    double getPreis() const;

    void setPreis(double preis);

    virtual double gesamtPreis() const = 0;




//virtuelle Methode die ersetzt wird, wie in Java
};

// implementierung des Konstruktors
