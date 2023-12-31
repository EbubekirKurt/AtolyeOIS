#ifndef MENU_H
#define MENU_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <thread>
#include <chrono>


#include "ZamanCizelgesi.h"
#include "Ogrenci.h"
#include "Ogretmen.h"

class Menu {
public:
    void anaMenuyuGoster();
    void MudurMenusu();
    void OgretmenMenusu();
	void OgrenciMenusu();
	
private:
	Ogrenci ogrenci;
	Ogretmen ogretmen;
	
    void ogrenciGirisi();
    void ogretmenGirisi();
    void mudurGirisi();
    
};

#endif  // MENU_H

