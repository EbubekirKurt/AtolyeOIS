#include "Dersler.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <unordered_set>

std::map<std::string, std::vector<std::string>> sinifDersleri = {
    {"BirinciSinif", {"Bilgi Iletisim", "Diferansiyel", "Programlama", "Fizik Lab", "Fizik", "Ingilizce", "Secmeli Ders 1"}},
    {"IkinciSinif", {"Inkilap Tarihi ve Ataturk Ilkeleri", "Ayrik Hesaplama Yapilari", "Diferansiyel Denklemler 2", "Programlama Atolyesi", "Elektrik Muh Giris", "Elektrik Labaratuvari", "Cebir", "Secmeli 2"}},
    {"UcuncuSinif", {"Veri Yapilari ve Algoritma", "Sayisal Sistemler", "Sayisal Sistemler Lab", "Ekonomi", "Veritabani Sistemleri", "Sistem Programlama", "Yapay Zeka", "Secmeli 3"}},
    {"DorduncuSinif", {"Bilgisayar Aglari", "Algoritma Analizi", "Yazilim Muh Surecleri", "Secmeli 4", "Bitirme Projesi","Ekoloji","Sosyal Sorumluluk"}}
};

DersProgrami::DersProgrami() : dersProgrami(5, std::vector<std::string>(4, "")) {}

void DersProgrami::BirlestirVeYazdir()
{
    std::ofstream hedefDosya(hedefDosyaAdi);

    if (!hedefDosya.is_open())
    {
        std::cerr << "Hedef dosya acilamadi: " << hedefDosyaAdi << std::endl;
        return;
    }

    for (const auto& dosyaAdi : sinifDosyaAdlari)
    {
        std::ifstream sinifDosya(dosyaAdi);
        if (sinifDosya.is_open())
        {
            hedefDosya << "\n\n----------------------\n";
            hedefDosya << "DERS PROGRAMI: " << dosyaAdi << "\n";
            hedefDosya << "----------------------\n\n";

            std::string satir;
            while (std::getline(sinifDosya, satir))
            {
                hedefDosya << satir << "\n";
            }

            sinifDosya.close();
        }
        else
        {
            std::cerr << "Sinif dosyasi acilamadi: " << dosyaAdi << std::endl;
        }
    }

    hedefDosya.close();
    std::cout << "Ders programlari birlestirildi ve " << hedefDosyaAdi << " dosyasina yazdirildi." << std::endl;
}
void DersProgrami::Olustur(const std::string& sinifAdi)
{
    const std::vector<std::string>& dersler = sinifDersleri[sinifAdi];

    std::random_device rd;
    std::mt19937 g(rd());

    for (const auto& ders : dersler)
    {
        std::vector<int> shuffledDays = {0, 1, 2, 3, 4};
        std::shuffle(shuffledDays.begin(), shuffledDays.end(), g);

        for (int day : shuffledDays)
        {
            std::vector<int> shuffledTimes = {0, 1, 2, 3};
            std::shuffle(shuffledTimes.begin(), shuffledTimes.end(), g);

            for (int time : shuffledTimes)
            {
                if (dersProgrami[day][time].empty())
                {
                    int toplamDersSayisi = 0;

                    // Hafta boyunca eklenmiþ ders sayýsýný hesapla
                    for (int g = 0; g < 5; ++g)
                    {
                        for (const auto& saat : dersProgrami[g])
                        {
                            if (saat == ders)
                            {
                                toplamDersSayisi++;
                            }
                        }
                    }
                    // Eðer hafta boyunca ayný ders 3 kez eklenmemiþse
                    if (toplamDersSayisi < 3)
                    {
                        dersProgrami[day][time] = ders;
                        break; 
                    }
                }
            }

            if (!dersProgrami[day][0].empty() && !dersProgrami[day][1].empty() &&
                !dersProgrami[day][2].empty() && !dersProgrami[day][3].empty())
            {
                break;
            }
        }
    }
    BirlestirVeYazdir();
}

void DersProgrami::Yazdir(const std::string& sinifAdi)
{
    std::cout << "\n\t" << sinifAdi << " DERS PROGRAMI\n";
    std::cout << "----------------------\n";
    DersPrograminiYazdir(dersProgrami);

    std::string dosyaAdi = sinifAdi + "_DersProgrami.txt"; 
    DersPrograminiDosyayaYazdir(dersProgrami, dosyaAdi);
}

bool DersProgrami::DersEkle(int gun, int saatIndex, const std::string& dersAdi)
{
    // Eðer o saatte ders yoksa
    if (dersProgrami[gun][saatIndex].empty())
    {
        int toplamDersSayisi = 0;

        // Hafta boyunca eklenmiþ ders sayýsýný hesapla
        for (int g = 0; g < 5; ++g)
        {
            for (const auto& saat : dersProgrami[g])
            {
                if (saat == dersAdi)
                {
                    toplamDersSayisi++;
                }
            }
        }

        // Eðer hafta boyunca ayný ders 3 kez eklenmemiþse
        if (toplamDersSayisi < 3)
        {
            dersProgrami[gun][saatIndex] = dersAdi;
            return true;
        }
    }
    return false;
}

void DersProgrami::DersPrograminiYazdir(const std::vector<std::vector<std::string>>& program)
{
    std::string gunler[5] = { "Pazartesi", "Sali", "Carsamba", "Persembe", "Cuma" };
    std::string saatler[4] = { "9:00 - 11:00", "11:00 - 13:00", "13:00 - 15:00", "15:00 - 17:00" };

    for (int gun = 0; gun < 5; ++gun)
    {
        std::cout << gunler[gun] << " : ";
        for (int saatIndex = 0; saatIndex < 4; ++saatIndex)
        {
            if (!program[gun][saatIndex].empty())
                std::cout << saatler[saatIndex] << " " << program[gun][saatIndex] << " | ";
        }
        std::cout << "\n";
    }
}

void DersProgrami::DersPrograminiDosyayaYazdir(const std::vector<std::vector<std::string>>& program, const std::string& dosyaAdi)
{
    std::ofstream dosya(dosyaAdi);
    if (dosya.is_open())
    {
        std::string gunler[5] = { "Pazartesi", "Sali", "Carsamba", "Persembe", "Cuma" };
        std::string saatler[4] = { "9:00 - 11:00", "11:00 - 13:00", "13:00 - 15:00", "15:00 - 17:00" };

        dosya << "DERS PROGRAMI\n";
        dosya << "----------------------\n";
        for (int gun = 0; gun < 5; ++gun)
        {
            dosya << gunler[gun] << " : ";
            for (int saatIndex = 0; saatIndex < 4; ++saatIndex)
            {
                if (!program[gun][saatIndex].empty())
                    dosya << saatler[saatIndex] << " " << program[gun][saatIndex] << " | ";
            }
            dosya << "\n";
        }

        dosya.close();
        std::cout << "\nDers programi " << dosyaAdi << " dosyasina yazdirildi. Islem Basarili :) \n";
    }
    else
    {
        std::cerr << "\nDosya acilamadi: " << dosyaAdi << "\n";
    }
}



