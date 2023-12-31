// ZamanCizelgesi.h

#ifndef ZAMANCIZELGESI_H
#define ZAMANCIZELGESI_H

#include <string>

class ZamanCizelgesi {
public:
    static const int GUN_SAYISI = 5; 
    static const int SAAT_SAYISI = 3; 

    ZamanCizelgesi(); 
    void CizelgeyeDersEkle(int gun, int saat, const std::string& dersAdi);
    void cizelgeyiYazdir() const;

private:
    char dersProgrami[GUN_SAYISI][SAAT_SAYISI];
};

#endif 

