#include "Dersler.h"
#include "mudur.h"
#include "Ogrenci.h"
#include "Ogretmen.h"
#include <algorithm>
#include <vector>

using namespace std;

void Mudur::MudurMenusuGoster() {
    int secim;
    std::string ogrenciIsmi;
    std::string ogretmenIsmi;

    Ogrenci ogrenci1;
    Ogrenci yeniOgrenci;
    DersProgrami program;
    
    Ogretmen ogretmen1;
    
        std::cout << "\nMudur Menusu:" << std::endl;
        std::cout << "1. Ogrenci Ekle" << std::endl;
        std::cout << "2. Ogrenci Cikar" << std::endl;
        std::cout << "3. Ogrencileri Goruntule" << std::endl;
        std::cout << "4. Ogretmen Ekle" << std::endl;
        std::cout << "5. Ogretmen Cikar" << std::endl;
        std::cout << "6. Ogretmen Goruntule" << std::endl;
        std::cout << "7. Ders Programi Olustur" << std::endl;
        

        std::cout << "8. Cikis" << std::endl;

        std::cout << "Seciminizi yapin (1-6): ";
        std::cin >> secim;

        switch (secim) {
        	
            case 1:
                yeniOgrenci.setOgrenciFromUserInput();
                yeniOgrenci.addNewOgrenciToFile(yeniOgrenci); 
                break;
                
                
            case 2:
			    std::cout << "Silmek istediðiniz öðrencinin adýný girin: ";
			    std::cin.ignore();
			    std::getline(std::cin, ogrenciIsmi);
			    ogrenci1.deleteOgrenciFromFile(ogrenciIsmi);
			    break;
				
				
            case 3:
                {
                    Ogrenci ogrenci;
                    std::vector<Ogrenci> ogrenciler = ogrenci.readOgrencilerFromFile();
                    
					ogrenci.displayOgrenci();
                    
                    for (const auto& ogr : ogrenciler) {
                        ogr.displayOgrenci();
                    }
                    break;
                }
            case 4:
            	while(true){
				
            	ogretmen1.setOgretmenFromUserInput();
            	ogretmen1.addNewOgretmenToFile(ogretmen1);
            }
            case 5:    
	        
			    std::cout << "Silmek istediðiniz öðretmenin adýný girin: ";
			    std::cin.ignore();
			    std::getline(std::cin,ogretmenIsmi);
			    Ogretmen::deleteOgretmen(ogretmenIsmi);
			    break;
                
            case 6:
			    {
			        Ogretmen ogretmen;
			        std::vector<Ogretmen> ogretmenler = ogretmen.readOgretmenlerFromFile();
			
			        ogretmen.displayOgretmenHeader();
			
			        for (const auto& ogr : ogretmenler) {
			            ogr.displayOgretmen();
			        }
			        break;
			    }
			
			case 7:
			{	
			DersProgrami dp1;
			DersProgrami dp2;
			DersProgrami dp3;
			DersProgrami dp4;
			
			dp1.Olustur("BirinciSinif");
			dp1.Yazdir("BirinciSinif");

			dp2.Olustur("IkinciSinif");
			dp2.Yazdir("IkinciSinif");
			
			dp3.Olustur("UcuncuSinif");
			dp3.Yazdir("UcuncuSinif");
			
			dp4.Olustur("DorduncuSinif");
			dp4.Yazdir("DorduncuSinif");
    		}
    		
            case 8:
                std::cout << "Mudur Menusunden cikiliyor..." << std::endl;
                break;
                
                
            default:
                std::cout << "Gecersiz secim. Lutfen tekrar deneyin." << std::endl;
        }

}

