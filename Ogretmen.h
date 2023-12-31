#ifndef OGRETMEN_H
#define OGRETMEN_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>

#include "Kisi.h"

class Ogretmen : public Kisiler {
private:
    std::string VerdigiDersler1;
    std::string VerdigiDersler2;
    static int ogretmenCount;
    int ogretmenID;
    static bool headerPrinted;


public:
    Ogretmen();

    Ogretmen(const std::string& isim, const std::string& anneAdi, const std::string& babaAdi,
             const std::string& DogumSehri, const std::string& OkulID, const std::string& Sifre,
             const std::string& VerdigiDersler1, const std::string& VerdigiDersler2);

    ~Ogretmen();
	
    void setVerdigiDersler1(const std::string& VerdigiDers1);
    std::string getVerdigiDersler1() const;

    void setVerdigiDersler2(const std::string& VerdigiDers2);
    std::string getVerdigiDersler2() const;

    void addNewOgretmenToFile(const Ogretmen& ogretmen);
    void setOgretmenFromUserInput();

    int getOgretmenID() const;

    static void displayOgretmenHeader();
    void displayOgretmen() const;

	static void deleteOgretmen(const std::string& ogretmenIsim);
    static void readOgretmenCountFromFile();
    static void writeOgretmenCountToFile();
    void IkiDersSectirme();
    void MesajlarinaBak() const;


    static std::vector<Ogretmen> readOgretmenlerFromFile();

    std::string generateOkulID(const std::string& isim);
    
	friend bool OgretmenKarsilastirma(const Ogretmen& ogretmen1, const Ogretmen& ogretmen2);

};

#endif

