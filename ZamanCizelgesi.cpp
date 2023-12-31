	#include "ZamanCizelgesi.h"
	#include <iostream>
	
	ZamanCizelgesi::ZamanCizelgesi() {
	    for (int i = 0; i < GUN_SAYISI; ++i) {
	        for (int j = 0; j < SAAT_SAYISI; ++j) {
	            dersProgrami[i][j] = '-';
	        }
	    }
	}
	
	void ZamanCizelgesi::CizelgeyeDersEkle(int gun, int saat, const std::string& dersAdi) {
	    if (gun >= 0 && gun < GUN_SAYISI && saat >= 0 && saat < SAAT_SAYISI) {
	        int dersUzunlugu = std::min(static_cast<int>(dersAdi.size()), 2);
	
	        for (int i = 0; i < dersUzunlugu; ++i) {
	            dersProgrami[gun][saat + i] = dersAdi[i];
	        }
	    } 
		
		else {
	        std::cerr << "Hata: Geçersiz gün veya saat indeksi.\n";
	    }
	}
	
	void ZamanCizelgesi::cizelgeyiYazdir() const {
	    std::cout << "\nDers Programi:\n\n";
	    for (int i = 0; i < GUN_SAYISI; ++i) {
	        std::cout << "| ";
	        for (int j = 0; j < SAAT_SAYISI; ++j) {
	            std::cout << dersProgrami[i][j] << " ";
	        }
	        std::cout << "|\n";
	    }
	    std::cout << "\n";
	}
