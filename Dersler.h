#ifndef DERSLER_H
#define DERSLER_H

#include <vector>
#include <string>
#include <map>

class DersProgrami
{
public:
	
	DersProgrami();
    void Olustur(const std::string& sinifAdi);
    void Yazdir(const std::string& sinifAdi);

private:
    bool DersEkle(int gun, int saatIndex, const std::string& dersAdi);
    void DersPrograminiYazdir(const std::vector<std::vector<std::string>>& program);
    void DersPrograminiDosyayaYazdir(const std::vector<std::vector<std::string>>& program, const std::string& dosyaAdi);

    std::vector<std::vector<std::string>> dersProgrami;
    
    std::vector<std::string> sinifDosyaAdlari;
    std::string hedefDosyaAdi;
    void BirlestirVeYazdir();
    
};

	extern std::map<std::string, std::vector<std::string>> sinifDersleri;


#endif 

