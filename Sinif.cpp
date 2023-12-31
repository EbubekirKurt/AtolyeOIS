#include "Sinif.h"
#include <iostream>
#include <iomanip>

Sinif::Sinif(const std::string& sinifAdi) : sinifAdi(sinifAdi) {}

void Sinif::DersPrograminiGoruntule() const {
    std::cout << "\n\t" << sinifAdi << " DERS PROGRAMI\n";
    std::cout << "----------------------\n";
    dersProgrami.DersPrograminiYazdir();
}

void Sinif::DersPrograminiOlustur() {
    dersProgrami.Olustur(sinifAdi);
}

bool Sinif::DersPrograminiKontrolEt(int gun, int saatIndex, const std::string& dersAdi) const {
    return !dersProgrami.DersEkle(gun, saatIndex, dersAdi);
}

