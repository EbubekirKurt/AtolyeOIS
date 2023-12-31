#include "menu.h"
#include "mudur.h"

using namespace std;
	
	void Menu::anaMenuyuGoster() {
    int secim;

    do {
        system("cls");

        cout << "\n==================== Ana Menu ====================" << endl;
        cout << "\t| 1. Ogrenci Girisi		|" << endl;
        cout << "\t| 2. Ogretmen Girisi		|" << endl;
        cout << "\t| 3. Mudur Girisi		|" << endl;
        cout << "\t| 4. Cikis			|" << endl;
        cout << "===================================================";

        cout << "\n\tSeciminizi yapin (1-4): ";
        cin >> secim;

        switch (secim) {
            case 1:
                ogrenciGirisi();
                break;
            case 2:
                ogretmenGirisi();
                break;
            case 3:
                mudurGirisi();
                break;
            case 4:
                cout << "\n\tProgramdan cikiliyor..." << endl;
                break;
            default:
                cout << "\n\tGecersiz secim. Lutfen tekrar deneyin." << endl;
        }

        cout << "\n\tDevam etmek icin Enter'a basin...";
        cin.ignore();
        cin.get();

    } 
	
	while (secim != 5);
}

void Menu::ogrenciGirisi() {
    string kullaniciAdi, sifre;
    cout << "\n\nOkul ID: ";
    cin >> kullaniciAdi;
    cout << "�ifre: ";
    cin >> sifre;

    ifstream dosya("Ogrenci.txt");
    if (!dosya.is_open()) {
        cout << "Dosya a��lamad�." << endl;
        return;
    }

    string satir;
    while (getline(dosya, satir)) {
        // d�z �izgi g�rene kadar ay�r�yoruz
        stringstream ss(satir);
        vector<string> veriler;
        string token;
        while (getline(ss, token, '|')) {
            veriler.push_back(token);
        }

        if (veriler.size() == 8) { 
            string dosyaKullaniciAdi = veriler[7];
            string dosyaSifre = veriler[6];

            // Bo�luklar� temizle
            dosyaKullaniciAdi.erase(remove_if(dosyaKullaniciAdi.begin(), dosyaKullaniciAdi.end(), ::isspace), dosyaKullaniciAdi.end());
            dosyaSifre.erase(remove_if(dosyaSifre.begin(), dosyaSifre.end(), ::isspace), dosyaSifre.end());
            sifre.erase(remove_if(sifre.begin(), sifre.end(), ::isspace), sifre.end());

            if (dosyaKullaniciAdi == kullaniciAdi && dosyaSifre == sifre) {
                cout << "Ba�ar�l�! Giri� Yap�l�yor!\n";
                //this_thread::sleep_for(chrono::seconds(5));
                system("cls");
                dosya.close();

                OgrenciMenusu();
                return;
            }
        }
    }

    cout << "Ge�ersiz Okul ID veya �ifre. Giri� ba�ar�s�z." << endl;
    dosya.close();
}

	void Menu::ogretmenGirisi() {
    string kullaniciAdi, sifre;
    cout << "\n\nOkul ID: ";
    cin >> kullaniciAdi;
    cout << "�ifre: ";
    cin >> sifre;

    ifstream dosya("Ogretmen.txt");
    if (!dosya.is_open()) {
        cout << "Dosya a��lamad�." << endl;
        return;
    }

    string satir;
    while (getline(dosya, satir)) {
        // d�z �izgi g�rene kadar ay�r�yoruz
        stringstream ss(satir);
        vector<string> veriler;
        string token;
        while (getline(ss, token, '|')) {
            veriler.push_back(token);
        }

        if (veriler.size() == 9) { 
            string dosyaKullaniciAdi = veriler[6];
            string dosyaSifre = veriler[5];

            // Bo�luklar� temizle
            dosyaKullaniciAdi.erase(remove_if(dosyaKullaniciAdi.begin(), dosyaKullaniciAdi.end(), ::isspace), dosyaKullaniciAdi.end());
            dosyaSifre.erase(remove_if(dosyaSifre.begin(), dosyaSifre.end(), ::isspace), dosyaSifre.end());
            sifre.erase(remove_if(sifre.begin(), sifre.end(), ::isspace), sifre.end());

            // Ekstra kontrol (debug ama�l�)
            // cout << "Dosya Okul ID: '" << dosyaKullaniciAdi << "', Giri� Okul ID: '" << kullaniciAdi << "'" << endl;
            // cout << "Dosya �ifre: '" << dosyaSifre << "', Giri� �ifre: '" << sifre << "'" << endl;

            if (dosyaKullaniciAdi == kullaniciAdi && dosyaSifre == sifre) {
                cout << "Ba�ar�l�! Giri� Yap�l�yor!\n";
                this_thread::sleep_for(chrono::seconds(5));
                system("cls");
                dosya.close();
                
                OgretmenMenusu();
                return;
            }
        }
    }

    cout << "Ge�ersiz Okul ID veya �ifre. Giri� ba�ar�s�z." << endl;
    dosya.close();
}	

	void Menu::mudurGirisi() {	
    std::string dogrulamaSifresi = "mudur";
    std::string girilenSifre;
    std::cout << "\n\nMudur Sifresi: ";
    std::cin >> girilenSifre;

    // Girilen �ifre ile do�rulama yap
    if (girilenSifre == dogrulamaSifresi) {
        std::cout << "Giris basarili. Hosgeldiniz.\n\n\t Naber Mudur?" << std::endl;
        //std::this_thread::sleep_for(std::chrono::seconds(2));
        system("cls");    
        
        Mudur mudur;
        mudur.MudurMenusuGoster();
    } 
    
	else {
        std::cout << "Giris basarisiz. Yanlis mudur sifresi." << std::endl;
    }
}
	
