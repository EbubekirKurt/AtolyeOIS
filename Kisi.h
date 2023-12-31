#ifndef KISI_H
#define KISI_H

#include <iostream>
#include <string>

class Kisiler {
public:
    void setIsim(const std::string& isim);
    std::string getIsim() const;

    void setOkulNo(const std::string& okulNo);
    std::string getOkulNo() const;

    void setTcKimlikNo(const std::string& tcKimlikNo);
    std::string getTcKimlikNo() const;

    void setBabaAdi(const std::string& babaAdi);
    std::string getBabaAdi() const;

    void setAnneAdi(const std::string& anneAdi);
    std::string getAnneAdi() const;

    void setDogumSehri(const std::string& dogumSehri);
    std::string getDogumSehri() const;

    void setSifre(const std::string& sifre);
    std::string getSifre() const;

    void setOkulID(const std::string& OkulID);
    std::string getOkulID() const;

	std::string isim;
    std::string okulNo;
    std::string TcKimlikNo;
    std::string babaAdi;
    std::string anneAdi;
    std::string dogumSehri;
    std::string sifre;
    std::string okulID;

private:
    
};

#endif

