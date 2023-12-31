#ifndef SINIF_H
#define SINIF_H

#include <string>
#include <vector>
#include "Dersler.h"

class Sinif {
public:
    Sinif(const std::string& sinifAdi);

    void DersPrograminiGoruntule() const;
    void DersPrograminiOlustur();

private:
    std::string sinifAdi;
    DersProgrami dersProgrami;

    bool DersPrograminiKontrolEt(int gun, int saatIndex, const std::string& dersAdi) const;
};

#endif

