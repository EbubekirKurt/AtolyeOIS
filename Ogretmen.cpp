#include "Ogretmen.h"
#include "Menu.h"

int Ogretmen::ogretmenCount = 0;
bool Ogretmen::headerPrinted = false;

Ogretmen::Ogretmen() {
    ogretmenID = ++ogretmenCount;
}

Ogretmen::Ogretmen(const std::string& isim, const std::string& anneAdi, const std::string& babaAdi,
                   const std::string& DogumSehri, const std::string& OkulID, const std::string& Sifre,
                   const std::string& VerdigiDersler1, const std::string& VerdigiDersler2)
    : Kisiler() {
    this->isim = isim;
    this->babaAdi = babaAdi;
    this->anneAdi = anneAdi;
    this->dogumSehri = DogumSehri;
    this->sifre = Sifre;
    this->okulID = OkulID;
    this->VerdigiDersler1 = VerdigiDersler1;
    this->VerdigiDersler2 = VerdigiDersler2;

    ogretmenID = ++ogretmenCount;
}

Ogretmen::~Ogretmen() {

}

void Ogretmen::setVerdigiDersler1(const std::string& VerdigiDers1) {
    this->VerdigiDersler1 = VerdigiDers1;
}

std::string Ogretmen::getVerdigiDersler1() const {
    return VerdigiDersler1;
}

void Ogretmen::setVerdigiDersler2(const std::string& VerdigiDers2) {
    this->VerdigiDersler2 = VerdigiDers2;
}

std::string Ogretmen::getVerdigiDersler2() const {
    return VerdigiDersler2;
}

int Ogretmen::getOgretmenID() const {
    return ogretmenID;
}

void Ogretmen::IkiDersSectirme() {
    const std::vector<std::string> tumDersler = {
        "Bilgi Iletisim", "Diferansiyel", "Programlama", "Fizik Lab", "Fizik", "Ingilizce", "Secmeli Ders 1",
        "Inkilap Tarihi ve Ataturk Ilkeleri", "Ayrik Hesaplama Yapilari", "Diferansiyel Denklemler 2",
        "Programlama Atolyesi", "Elektrik Muh Giris", "Elektrik Labaratuvari", "Cebir", "Secmeli 2",
        "Veri Yapilari ve Algoritma", "Sayisal Sistemler", "Sayisal Sistemler Lab", "Ekonomi",
        "Veritabani Sistemleri", "Sistem Programlama", "Yapay Zeka", "Secmeli 3",
        "Bilgisayar Aglari", "Algoritma Analizi", "Yazilim Muh Surecleri", "Secmeli 4", "Bitirme Projesi"
    };

    std::cout << "\n\nDers Listesi:\n";
    for (size_t i = 0; i < tumDersler.size(); ++i) {
        std::cout << i + 1 << ". " << tumDersler[i] << "\n";
    }

    std::vector<int> secilenDersler;
    for (int i = 0; i < 2; ++i) {
        int dersIndex;
        do {
            std::cout << "Ders " << i + 1 << " icin seciminiz (1-" << tumDersler.size() << "): ";
            std::cin >> dersIndex;

            if (std::cin.fail() || dersIndex < 1 || dersIndex > tumDersler.size()) {
                std::cerr << "Error: Geçersiz ders indeksi. Lütfen geçerli bir indeks girin.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (std::find(secilenDersler.begin(), secilenDersler.end(), dersIndex) != secilenDersler.end()) {
                std::cerr << "Error: Ayni dersi tekrar secemezsiniz. Lütfen farkli bir ders secin.\n";
            } else {
                secilenDersler.push_back(dersIndex);
                break;
            }
        } while (true);
    }

    setVerdigiDersler1(tumDersler[secilenDersler[0] - 1]);
    setVerdigiDersler2(tumDersler[secilenDersler[1] - 1]);

    std::cout << "\n\nSectiginiz Dersler:\n";
    for (int i = 0; i < 2; ++i) {
        std::cout << i + 1 << ". " << tumDersler[secilenDersler[i] - 1] << "\n";
    }
}

void Ogretmen::addNewOgretmenToFile(const Ogretmen& ogretmen) {
    std::ofstream outFile("Ogretmen.txt", std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return;
    }

    outFile << ogretmen.getOgretmenID() << " | " << ogretmen.getIsim() << " | " << ogretmen.getBabaAdi() << " | "
            << ogretmen.getAnneAdi() << " | " << ogretmen.getDogumSehri() << " | " << ogretmen.getSifre() << " | "
            << generateOkulID(ogretmen.getIsim()) << " | " << ogretmen.getVerdigiDersler1() << " | " << ogretmen.getVerdigiDersler2();

    outFile << std::endl;

    if (outFile.fail()) {
        std::cerr << "Error: Failed to write to file." << std::endl;
    }
    else
    {
    	std::cout << "\n\nOgretmen Ekleme Islemi Basari ile Sonuclandi :)\n";
	}

    outFile.close();
}

void Ogretmen::setOgretmenFromUserInput() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Ogretmenin Ismi: ";
    std::getline(std::cin, isim);

    std::cout << "Anne Adi: ";
    std::getline(std::cin, anneAdi);

    std::cout << "Baba Adi: ";
    std::getline(std::cin, babaAdi);

    std::cout << "Dogum Sehri: ";
    std::getline(std::cin, dogumSehri);
	
    okulID = generateOkulID(isim);

    do {
        std::cout << "Sifre (en az 8 karakter, en az bir harf, bir sayý ve bir özel karakter içermelidir): ";
        std::getline(std::cin, sifre);

        if (sifre.length() < 8) {
            std::cerr << "Error: Þifre en az 8 karakter içermelidir.\n";
            continue;
        }

        if (std::none_of(sifre.begin(), sifre.end(), ::isalpha)) {
            std::cerr << "Error: Þifre en az bir harf içermelidir.\n";
            continue;
        }

        if (std::none_of(sifre.begin(), sifre.end(), ::isdigit)) {
            std::cerr << "Error: Þifre en az bir sayý içermelidir.\n";
            continue;
        }
        if (std::none_of(sifre.begin(), sifre.end(), ::ispunct)) {
            std::cerr << "Error: Þifre en az bir özel karakter içermelidir.\n";
            continue;
        }

        break; 
    } while (true);

    IkiDersSectirme();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    ogretmenID = ++ogretmenCount;
}

std::string Ogretmen::generateOkulID(const std::string& isim) {
    std::string cleanedIsim = isim;
    cleanedIsim.erase(std::remove_if(cleanedIsim.begin(), cleanedIsim.end(), ::isspace), cleanedIsim.end());

    std::transform(cleanedIsim.begin(), cleanedIsim.end(), cleanedIsim.begin(), ::tolower);
    return cleanedIsim + "@beykoz.edu.tr";
}

void Ogretmen::displayOgretmenHeader() {
    const int isimSoyisimWidth = 20;
    const int otherFieldWidth = 17;

    std::cout << std::left << std::setw(3) << "ID" << "|"
			  << std::left << std::setw(isimSoyisimWidth-1) << "ISIM-SOYISIM" << "|"
              << std::left << std::setw(otherFieldWidth) << "ANNE ADI" << "|"
              << std::left << std::setw(otherFieldWidth) << "BABA ADI" << "|"
              << std::left << std::setw(otherFieldWidth) << "DOGUM YERI" << "|"
              << std::left << std::setw(otherFieldWidth) << "SIFRE" << "|"
              << std::left << std::setw(35) << "MAIL ADRESI" << "|"
              << std::left << std::setw(40) << "VERDIGI DERSLER" << std::endl;

    std::cout << std::setfill('-') << std::setw(isimSoyisimWidth + 7 * otherFieldWidth) << "-" << std::setfill(' ') << std::endl;
}

void Ogretmen::displayOgretmen() const {
    const int isimSoyisimWidth = 0;
    const int otherFieldWidth = 17;

    if (!headerPrinted) {
        system("cls");
        displayOgretmenHeader();
        headerPrinted = true;
    }

    std::cout << std::left << std::setw(5) << getOgretmenID() 
              << std::left << std::setw(isimSoyisimWidth) << getIsim() << "|"
              << std::left << std::setw(otherFieldWidth) << getAnneAdi() << "|"
              << std::left << std::setw(otherFieldWidth) << getBabaAdi() << "|"
              << std::left << std::setw(otherFieldWidth) << getDogumSehri() << "|"
              << std::left << std::setw(otherFieldWidth) << getSifre() << "|"
              << std::left << std::setw(otherFieldWidth) << getOkulID() << "|"
              << std::left << std::setw(35) << getVerdigiDersler1() << "|"
              << std::left << std::setw(40) << getVerdigiDersler2() << std::endl;
}

std::vector<Ogretmen> Ogretmen::readOgretmenlerFromFile() {
    std::vector<Ogretmen> ogretmenler;

    std::ifstream inFile("Ogretmen.txt");
    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
        return ogretmenler;
    }

    while (true) {
        Ogretmen ogretmen;

        inFile >> ogretmen.ogretmenID;
        if (inFile.eof()) {
            break;
        }

        inFile.ignore(); // Ignore the '|' character

        std::getline(inFile, ogretmen.isim, '|');
        std::getline(inFile, ogretmen.anneAdi, '|');
        std::getline(inFile, ogretmen.babaAdi, '|');
        std::getline(inFile, ogretmen.dogumSehri, '|');
        std::getline(inFile, ogretmen.sifre, '|');
        std::getline(inFile, ogretmen.okulID, '|');
        std::getline(inFile, ogretmen.VerdigiDersler1, '|');
        std::getline(inFile, ogretmen.VerdigiDersler2);

        ogretmenler.push_back(ogretmen);
    }

    inFile.close();
    return ogretmenler;
}

void Ogretmen::deleteOgretmen(const std::string& ogretmenIsmi) {
    std::ifstream inFile("Ogretmen.txt");
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
    bool ogretmenFound = false;

    while (std::getline(inFile, line)) {
        if (line.find("| " + ogretmenIsmi + " |") != std::string::npos) {
            ogretmenFound = true;
        } else {
            outFile << line << std::endl;
        }
    }

    inFile.close();
    outFile.close();

    if (!ogretmenFound) {
        std::cerr << "Hata: Ogretmen bulunamadý." << std::endl;
        remove("temp.txt"); 
        return;
    }

    remove("Ogretmen.txt");
    rename("temp.txt", "Ogretmen.txt");

    std::cout << "Ogretmen baþarýyla silindi." << std::endl;
}

bool OgretmenKarsilastirma(const Ogretmen& ogretmen1, const Ogretmen& ogretmen2) {
    return ogretmen1.ogretmenID == ogretmen2.ogretmenID;
}

void Ogretmen::MesajlarinaBak() const {
    std::string dosyaAdi = isim + "_Mesaj.txt";
    std::ifstream mesajDosyasi(dosyaAdi);

    if (!mesajDosyasi.is_open()) {
        std::cerr << "Hata: Mesaj dosyasi okunamadi." << std::endl;
        return;
    }

    std::cout << "\n------- MESAJLAR -------\n";
    std::cout << "Ogretmen: " << isim << "\n\n";

    std::string satir;
    while (std::getline(mesajDosyasi, satir)) {
        std::cout << satir << "\n";
    }

    mesajDosyasi.close();
    std::cout << "------------------------\n";
}

void Menu::OgretmenMenusu() {
		std::cout << "\n\n\t\t\tHosgeldin " << std::endl;
		std::cout << "\tBugün size nasýl yardýmcý olabilirim?\n\n\n";
		
		std::cout << "\t---------------- [OGRETMEN MENUSU] ----------------\n";
		std::cout << "\t[1] - Mesajlarina bak \n";
		std::cout << "\t[2] - \n";
		std::cout << "\t[3] - Cikis Yap \n";
        std::cout << "\n\t-------------------------------------------------";
	Ogretmen ogretmen;

    char b;
    do {
        std::cout << "\n\t\tSeciminizi yapin: ";
        std::cin >> b;

        switch (b) {
            case '1':
            	ogretmen.MesajlarinaBak();
                break;
                
            case '2':
                break;

            default:
                std::cerr << "Hata: Gecersiz secim. Lutfen tekrar deneyin." << std::endl;
        }
    } while (b != '1');
}
