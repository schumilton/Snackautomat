#include <iostream>

#include "Getraenk.h"
#include "Snack.h"
#include "Platz.h"
#include "Snackautomat.h"
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>


double *geldeinzahl() {
    int menge = 0;
    double einzahlung = 0;
    bool abbrechen = false;
    double *geld = new double[8];

    while (abbrechen == 0) {
        std::cout << "Was möchtest du einzahlen? 20.0; 10.0; 5.0; 2.0; 1.0; 0.5; 0.2; 0.1" << std::endl;
        std::cin >> einzahlung;
        std::cout << "Wie oft?" << std::endl;
        std::cin >> menge;

        switch ((int) einzahlung * 10) {
            case 200:
                geld[0] = geld[0] + menge;
                break;
            case 100:
                geld[1] = geld[1] + menge;
                break;
            case 50:
                geld[2] = geld[2] + menge;
                break;
            case 20:
                geld[3] = geld[3] + menge;
                break;
            case 10:
                geld[4] = geld[4] + menge;
                break;
            case 5:
                geld[5] = geld[5] + menge;
                break;
            case 2:
                geld[6] = geld[6] + menge;
                break;
            case 1:
                geld[7] = geld[7] + menge;
                break;
            default:
                std::cout << "falsche Eingabe" << std::endl;
        }
        std::cout << geld[0];
        std::cout << "Möchtest du abbrechen? 1= Ja , 0=Nein ";
        std::cin >> abbrechen;
    }
    return geld;
}

void kaufen(Snackautomat a) {

    double *geld = geldeinzahl();
    double guthaben = 0;
    int menge;
    std::vector<std::string> artikel;
int abbruch;
    std::string name;
    double preis;
    double gesamtPreis;
    double bargeld[8] = {
            20.0,
            10.0,
            5.0,
            2.0,
            1.0,
            0.5,
            0.2,
            0.1
    };


    std::time_t jetzt = std::time(nullptr);
    const char *zeitFormat = "%Y-%m-%d %H:%M:%S";
    char zeitPuffer[80];
    std::string directory = "../Rechnungen/";

    std::string fileFormat = ".txt";

    std::strftime(zeitPuffer, sizeof(zeitPuffer), zeitFormat, std::localtime(&jetzt));// Zeit in den Puffer schreiben
    std::string zeitString = zeitPuffer;// Puffer in einen std::string umwandeln
    std::string date = zeitString;
    std::string filename = directory + date + fileFormat;
    std::ofstream file(filename);

    for (int i = 0; i < 8; i++) {
        file<< bargeld[i]<<": "<< geld[i] << " = "<< geld[i]* bargeld[i]<<std::endl;
        guthaben += geld[i]* bargeld[i];
    }
    file<< "Guthaben "<<guthaben;
while(1) {
    a.alleWarenAusgeben();
    std::cout << "Welche Ware möchtest du?";
    std::cin >> name;
    std::cout << "Wie oft?";
    std::cin >> menge;


    Platz *gefundenerPlatz = a.warenSuchen(name);
    std::cout << gefundenerPlatz;

    std::cout << "drimnnnejfneo";
    if (gefundenerPlatz->getSnack() != nullptr|gefundenerPlatz->getGetraenk() != nullptr) {

        if (gefundenerPlatz->getGetraenk() == nullptr) {
            preis = gefundenerPlatz->getSnack()->getPreis();




        } else {
            preis = gefundenerPlatz->getGetraenk()->getPreis();
            gesamtPreis = gefundenerPlatz->getGetraenk()->getPfand()* menge;



        }
        if (gefundenerPlatz->entnehmen(menge)) {
            gesamtPreis += preis*menge;
            if(gesamtPreis>= guthaben) {
                std::cout << " zu wenig geld auf dem konto";
            }
            else {
                guthaben= guthaben-gesamtPreis;
                gesamtPreis= 0;
                std::cout << "test";
                artikel.push_back(name);
                artikel.push_back(std::to_string(menge));
                artikel.push_back(std::to_string(preis));
                artikel.push_back(std::to_string(preis * 1.19));
                //       if (gefundenerPlatz->getGetraenk()!) {
                //         artikel.push_back(std::to_string(gefundenerPlatz->getGetraenk()->getPfand()));
                //     }

                std::cout << "Artikel wurde erfolgreich entnommen" << artikel[0];
                file << artikel[0];
                file << artikel[2];
                file << menge;
                artikel.clear();
            }

        }
    }
    file << "\n";
    std::cout<< "Bist du fertig? ja = 1 ,0 = nein";


    std::cin >> abbruch;
    if(abbruch==1) {


        for (int i = 0; i < 8; i++) {
            double wert = bargeld[i];
            int anzahl = static_cast<int>(geld[i]);
            while (anzahl > 0 && guthaben + wert <= guthaben) {
                guthaben += wert;
                anzahl--;
            }
            geld[i] = anzahl;
        }
        break;
    }
}

a.alleWarenAusgeben();
 //   std::cout << geld[0];

    file.close();


}

void auffuelle(Snackautomat a) {
    std::string filename = "../Auffuellungen/auffuelle.txt";
    std::ifstream file(filename);
    std::string line;
    std::string delimiter = ",";
    std::vector<std::string> articleInfo;
    Platz* p;

    int i = 0;

    if (file.is_open()) {
        while (std::getline(file, line)) {

            std::string token;
            size_t pos = line.find(delimiter);

            while (pos != std::string::npos) {


                token = line.substr(0, pos);
                articleInfo.push_back(token);


                // std::cout << token << std::endl;
                line.erase(0, pos + delimiter.length());
                pos = line.find(delimiter);
                i++;
            }

            if (articleInfo.size() == 4) {
                std::cout << articleInfo[2] << std::endl;
                Getraenk *g1 = new Getraenk(articleInfo[0], std::stod(articleInfo[2]), std::stod(articleInfo[3]));
                //  Getraenk* g = &g1;
               p=  a.leerenPlatzSuchen();
               p->setGetraenk(g1);
                p->setMenge(std::stoi(articleInfo[1]));
                std::cout<< "234232423";
            }
            if (articleInfo.size() == 3) {
                std::cout << articleInfo[2] << std::endl;
                Snack *s1 = new Snack(articleInfo[0], std::stod(articleInfo[2]));
                std::cout<< "efefwfwfaef";

                p= a.leerenPlatzSuchen();
                p->setSnack(s1);

                p->setMenge(std::stoi(articleInfo[1]));
            }

            articleInfo.clear();

        }

        file.close();
    } else {
        std::cout << "Failed to open the file." << std::endl;
    }
    //gehe
    //leerenPlatz Suchen
    //nachdem ein Leerer Platz gefunden ist objekteinschreiben

}

int main() {
    Platz e = Platz();
    Snack m = Snack("ar", 23);
    e.setSnack(&m);
    double bargeld[8][2] = {
            {20.0, 10.0},
            {10.0, 10.0},
            {5.0,  10.0},
            {2.0,  10.0},
            {1.0,  10.0},
            {0.5,  10.0},
            {0.2,  10.0},
            {0.1,  10.0}
    };


    //  std::cout <<  e.getSnack()->getArtikelName() << std::endl;
    Getraenk t("ar", 23, 0.2);

    //   std::cout <<  m.gesamtPreis();
    Platz *r = new Platz[20];
    Platz test = Platz();
    test.setGetraenk(&t);



    e.getSnack()->getArtikelName();

    Snackautomat *w = new Snackautomat(std::string("A2"), bargeld, r);
   auffuelle(*w);
   kaufen(*w);
  if(test.getGetraenk() == nullptr){
      std::cout<< "test";
  }



    // std::cout<<w.warenSuchen("Snickers").getSnack()->getArtikelName();
    w->alleWarenAusgeben();


    return 0;

}
