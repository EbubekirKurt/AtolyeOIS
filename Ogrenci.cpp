#include "Ogrenci.h"
#include "Menu.h"
#include "Dersler.h"

#include <iostream>
#include <sstream>
#include<string>

// Hasan hoca buradan soru sorar en azýndan ne yaptýðýma bak.

bool Ogrenci::headerPrinted = false;

Ogrenci::Ogrenci()
    : isim(""), okulNo(""), tcKimlikNo(""), babaAdi(""), anneAdi(""), dogumSehri(""), sifre(""), OkulID("") {}

Ogrenci::Ogrenci(const std::string& isim, const std::string& okulNo, const std::string& tcKimlikNo,
                 const std::string& babaAdi, const std::string& anneAdi, const std::string& dogumSehri, const std::string& sifre)
    : isim(isim), okulNo(okulNo), tcKimlikNo(tcKimlikNo), babaAdi(babaAdi), anneAdi(anneAdi), dogumSehri(dogumSehri), sifre(sifre), OkulID("") {}

void Ogrenci::setIsim(const std::string& isim) {
    this->isim = isim;
}

std::string Ogrenci::getIsim() const {
    return isim;
}

void Ogrenci::setOkulNo(const std::string& okulNo) {
    this->okulNo = okulNo;
}

std::string Ogrenci::getOkulNo() const {
    return okulNo;
}

void Ogrenci::setTcKimlikNo(const std::string& tcKimlikNo) {
    this->tcKimlikNo = tcKimlikNo;
}

std::string Ogrenci::getTcKimlikNo() const {
    return tcKimlikNo;
}

void Ogrenci::setBabaAdi(const std::string& babaAdi) {
    this->babaAdi = babaAdi;
}

std::string Ogrenci::getBabaAdi() const {
    return babaAdi;
}

void Ogrenci::setAnneAdi(const std::string& anneAdi) {
    this->anneAdi = anneAdi;
}

std::string Ogrenci::getAnneAdi() const {
    return anneAdi;
}

void Ogrenci::setDogumSehri(const std::string& dogumSehri) {
    this->dogumSehri = dogumSehri;
}

std::string Ogrenci::getDogumSehri() const {
    return dogumSehri;
}

void Ogrenci::setSifre(const std::string& sifre) {
    this->sifre = sifre;
}

std::string Ogrenci::getSifre() const {
    return sifre;
}

void Ogrenci::setOkulID(const std::string& OkulID) {
    this->OkulID = OkulID;
}

std::string Ogrenci::getOkulID() const {
    return OkulID;
}

void Ogrenci::displayOgrenciHeader() {
    const int isimSoyisimWidth = 25;
    const int otherFieldWidth = 15;

    std::cout << std::left << std::setw(isimSoyisimWidth) << "ISIM-SOYISIM" << "|"
              << std::left << std::setw(otherFieldWidth) << "OKUL NO" << "|"
              << std::left << std::setw(otherFieldWidth) << "TCKIMLIK NO" << "|"
              << std::left << std::setw(otherFieldWidth) << "BABA ADI" << "|"
              << std::left << std::setw(otherFieldWidth) << "ANNE ADI" << "|"
              << std::left << std::setw(otherFieldWidth) << "DOGUM YERI" << "|"
              << std::left << std::setw(otherFieldWidth) << "SIFRE" << "|"
              << std::left << std::setw(otherFieldWidth) << "OKUL ID" << std::endl;

    std::cout << std::setfill('-') << std::setw(isimSoyisimWidth + 7 * otherFieldWidth) << "-" << std::setfill(' ') << std::endl;
}

void Ogrenci::displayOgrenci() const {
    const int isimSoyisimWidth = 25;
    const int otherFieldWidth = 15;

    if (!headerPrinted) {
    	system("cls");
        displayOgrenciHeader();
        headerPrinted = true;
    }

    if (!getIsim().empty()) {
        std::istringstream iss(getIsim());
        std::string firstName, lastName;
        iss >> firstName;
        iss >> std::ws;  // boþluklardan oluþacak sorunlarý bunla kaldýrdýk.
        std::getline(iss, lastName);

        std::cout << std::left << std::setw(isimSoyisimWidth) << (firstName + " " + lastName) << "|"
                  << std::left << std::setw(otherFieldWidth) << getOkulNo() << "|"
                  << std::left << std::setw(otherFieldWidth) << getTcKimlikNo() << "|"
                  << std::left << std::setw(otherFieldWidth) << getBabaAdi() << "|"
                  << std::left << std::setw(otherFieldWidth) << getAnneAdi() << "|"
                  << std::left << std::setw(otherFieldWidth) << getDogumSehri() << "|"
                  << std::left << std::setw(otherFieldWidth) << getSifre() << "|"
                  << std::left << std::setw(otherFieldWidth) << getOkulID() << std::endl;
    }
}

void Ogrenci::addNewOgrenciToFile(const Ogrenci& ogrenci) {
    std::ofstream outFile("Ogrenci.txt", std::ios::app);

    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return;
    }

    outFile << ogrenci.getIsim() << " | " << ogrenci.getOkulNo() << " | " << ogrenci.getTcKimlikNo() << " | "
            << ogrenci.getBabaAdi() << " | " << ogrenci.getAnneAdi() << " | " << ogrenci.getDogumSehri() << " | "
            << ogrenci.getSifre() << " | " << ogrenci.getOkulID() << std::endl;

    if (outFile.fail()) {
        std::cerr << "Error: Failed to write to file." << std::endl;
    }

    outFile.close();
}

bool Ogrenci::operator!=(const Ogrenci& other) const {
    return (isim != other.isim || okulNo != other.okulNo);
}

void Ogrenci::deleteOgrenciFromFile(const std::string& ogrenciIsmi) {
    std::ifstream inFile("Ogrenci.txt");
    if (!inFile.is_open()) {
        std::cerr << "Hata: Dosya açýlamadý." << std::endl;
        return;
    }

    std::ofstream outFile("temp.txt");
    if (!outFile.is_open()) {
        std::cerr << "Hata: Geçici dosya açýlamadý." << std::endl;
        inFile.close();
        return;
    }

    std::string line;
    bool ogrenciFound = false;

    while (std::getline(inFile, line)) {
        // Büyük/küçük harf duyarlýlýðýný kontrol etmek için compare kullanýlýr
        if (line.find("|") != std::string::npos &&
            line.find(ogrenciIsmi) != std::string::npos &&
            line.compare(0, ogrenciIsmi.length(), ogrenciIsmi) == 0) {
            ogrenciFound = true;
        } else {
            outFile << line << std::endl;
        }
    }

    inFile.close();
    outFile.close();

    if (!ogrenciFound) {
        std::cerr << "Hata: Ogrenci bulunamadý." << std::endl;
        remove("temp.txt");
        return;
    }

    remove("Ogrenci.txt");
    rename("temp.txt", "Ogrenci.txt");

    std::cout << "Ogrenci baþarýyla silindi." << std::endl;
}

std::vector<Ogrenci> Ogrenci::readOgrencilerFromFile() {
    std::ifstream inFile("Ogrenci.txt");
    std::vector<Ogrenci> ogrenciler;

    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
        return ogrenciler;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        Ogrenci ogrenci;


		// | karakterine göre ayýrýyoz
        std::getline(iss, ogrenci.isim, '|');
        std::getline(iss, ogrenci.okulNo, '|');
        std::getline(iss, ogrenci.tcKimlikNo, '|');
        std::getline(iss, ogrenci.babaAdi, '|');
        std::getline(iss, ogrenci.anneAdi, '|');
        std::getline(iss, ogrenci.dogumSehri, '|');
        std::getline(iss, ogrenci.sifre, '|');
        std::getline(iss, ogrenci.OkulID, '|');

        ogrenciler.push_back(ogrenci);
    }
    inFile.close();

    return ogrenciler;
}

void Ogrenci::setOgrenciFromUserInput() {
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Önceki giriþi temizle

std::cout << "Ogrenci Ismi: ";
std::getline(std::cin, isim);

std::cout << "Okul Numarasi: ";
std::getline(std::cin, okulNo);

std::cout << "TC Kimlik No: ";
std::getline(std::cin, tcKimlikNo);

std::cout << "Baba Adi: ";
std::getline(std::cin, babaAdi);

std::cout << "Anne Adi: ";
std::getline(std::cin, anneAdi);

std::cout << "Dogum Sehri: ";
std::getline(std::cin, dogumSehri);

std::cout << "Sifre: ";
std::getline(std::cin, sifre);

    OkulID = ""; 

    for (char c : isim) {
        if (isalpha(c)) {  // sadece harf karakterlerini kontrol et
            OkulID += tolower(c);  // küçük harfe çevirerek okul id'ye ekle
        }
	}
}



void Ogrenci::DersProgramiGoruntule() const {
    int sinif;
   
    std::cout << "\t Sýnýfýnýz : ";
    std::cin >> sinif;

    // Sýnýfýn ders programýný oku ve ekrana yazdýr
    std::string sinifDosyaAdi = "";
    switch (sinif) {
        case 1:
            sinifDosyaAdi = "BirinciSinif_DersProgrami.txt";
            break;
        case 2:
            sinifDosyaAdi = "IkinciSinif_DersProgrami.txt";
            break;
        case 3:
            sinifDosyaAdi = "UcuncuSinif_DersProgrami.txt";
            break;
        case 4:
            sinifDosyaAdi = "DorduncuSinif_DersProgrami.txt";
            break;
        default:
            std::cerr << "Hata: Geçersiz sýnýf numarasý." << std::endl;
            return;
    }

    std::ifstream dersProgramiFile(sinifDosyaAdi);
    if (!dersProgramiFile.is_open()) {
        std::cerr << "Hata: Ders programi dosyasi acilamadi." << std::endl;
        return;
    }

    std::string line;
    std::cout << "\n" << sinif << ". SINIF DERS PROGRAMI\n";
    while (std::getline(dersProgramiFile, line)) {
        std::cout << line << std::endl;
    }

    dersProgramiFile.close();
}

void Ogrenci::OgretmenineMesajBirak() const {
    std::string konuBasligi, ogretmenIsmi, mesaj;

    std::cout << "Konu Basligi: ";
    std::cin.ignore(); 
    std::getline(std::cin, konuBasligi);

    std::cout << "Gonderilecek Ogretmen: ";
    std::getline(std::cin, ogretmenIsmi);

    std::cout << "Mesaj: ";
    std::getline(std::cin, mesaj);

    std::string dosyaAdi = ogretmenIsmi + "_Mesaj.txt";
    std::ofstream mesajDosyasi(dosyaAdi);

    if (!mesajDosyasi.is_open()) {
        std::cerr << "Hata: Mesaj dosyasi olusturulamadi." << std::endl;
        return;
    }

    mesajDosyasi << "Konu Basligi: " << konuBasligi << "\n\n";
    mesajDosyasi << "Mesaj:\n" << mesaj << "\n";

    mesajDosyasi.close();

    std::cout << "Mesaj basariyla gonderildi." << std::endl;
}

void Ogrenci::UniversitenHakkindaBilgiAl() const {
    std::cout << "\n\n\n\t\t-------------[ BEYKOZ UNIVERSITESI ]------------\n";
    std::cout << "\t\t| Beykoz Üniversitesi, 2008 yýlýnda Ýstanbul'un  |\n";
    std::cout << "\t\t| güzel ve tarihi semtlerinden biri olan         |\n";
    std::cout << "\t\t| Beykoz'da kurulmuþ bir üniversitedir.          |\n";
    std::cout << "\t\t| Üniversite, geniþ kampüsü, nitelikli           |\n";
    std::cout << "\t\t| öðretim kadrosu ve çeþitli akademik birimleri  |\n";
    std::cout << "\t\t| ile bilinmektedir. Beykoz Üniversitesi,        |\n";
    std::cout << "\t\t| öðrencilere modern eðitim olanaklarý,          |\n";
    std::cout << "\t\t| kültürel etkinlikler ve sosyal imkanlar        |\n";
    std::cout << "\t\t| sunar. Detaylý bilgi ve baþvuru için           |\n";
    std::cout << "\t\t| üniversitenin resmi web sitesini ziyaret       |\n";
    std::cout << "\t\t| edebilirsiniz.                                 |\n";
    std::cout << "\t\t|                                                |\n";
    std::cout << "\t\t|  beykoz.edu.tr          gdsc.community.dev     |\n";
    std::cout << "\t\t--------------------------------------------------\n";
}

void Ogrenci::AlabileceginDersleriListele() const {
    

    std::cout << "\n\n\t\t--------------[ ALABÝLECEÐÝN DERSLER ]--------------\n";

    for (const auto& sinifDersleriPair : sinifDersleri) {
        const std::string& sinif = sinifDersleriPair.first;
        const std::vector<std::string>& dersler = sinifDersleriPair.second;

        std::cout << "\t\t" << sinif << " DERSLERI:\n";
        for (const auto& ders : dersler) {
            std::cout << "\t\t- " << ders << "\n";
        }
        std::cout << "\n";
    }
}


void Menu::OgrenciMenusu() {
		std::cout << "\n\n\t\t\tHosgeldin " << std::endl;
		std::cout << "\tBugün size nasýl yardýmcý olabilirim?\n\n\n";
		
		std::cout << "\t----------------- [OGRENCI MENUSU] ----------------\n";
		std::cout << "\t[1] - Ders Programini Goruntule \n";
		std::cout << "\t[2] - Ogretmenine Mesaj Birak \n";
		std::cout << "\t[3] - Universiten Hakkinda Bilgi Al \n";
		std::cout << "\t[4] - Alabilecegin Derslerin Listesi \n";
		std::cout << "\t[5] - Giris Ekranina Geri Don \n";
        std::cout << "\n\t-------------------------------------------------";


    char a;
    do {
        std::cout << "\n\t\tSeciminizi yapin: ";
        std::cin >> a;

        switch (a) {
            case '1':
                ogrenci.DersProgramiGoruntule();
                break;
                
            case '2':
                ogrenci.OgretmenineMesajBirak();
                break;

            case '3':
                ogrenci.UniversitenHakkindaBilgiAl();
                break;

            case '4':
                ogrenci.AlabileceginDersleriListele();
                break;

            case '5':
                break;

            default:
                std::cerr << "Hata: Gecersiz secim. Lutfen tekrar deneyin." << std::endl;
        }
    } while (a != '5');
}
