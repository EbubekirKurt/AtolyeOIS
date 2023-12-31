#ifndef OGRENCI_H
#define OGRENCI_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <cctype>
#include <vector>
#include <sstream>
#include <map>

class Ogrenci {
public:
    Ogrenci();
    Ogrenci(const std::string& isim, const std::string& okulNo, const std::string& tcKimlikNo,
            const std::string& babaAdi, const std::string& anneAdi, const std::string& dogumSehri, const std::string& sifre);

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

    void displayOgrenci() const;
    void addNewOgrenciToFile(const Ogrenci& ogrenci);
    void deleteOgrenciFromFile(const std::string& ogrenciIsmi);
    std::vector<Ogrenci> readOgrencilerFromFile();
    void setOgrenciFromUserInput();
    
    int BelirleSinif() const; 
    void KisiselBilgileriGoruntule() const; 
    void DersProgramiGoruntule() const; 
	void OgretmenineMesajBirak() const;
	void UniversitenHakkindaBilgiAl() const;
	void AlabileceginDersleriListele() const;


    
    bool operator!=(const Ogrenci& other) const;


private:
    std::string isim;
    std::string okulNo;
    std::string tcKimlikNo;
    std::string babaAdi;
    std::string anneAdi;
    std::string dogumSehri;
    std::string sifre;
    std::string OkulID;

    static bool headerPrinted;

    static void displayOgrenciHeader();
};

#endif

