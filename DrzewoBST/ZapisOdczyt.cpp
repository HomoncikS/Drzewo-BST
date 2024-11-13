#include "ZapisOdczyt.h"
#include <fstream>

void ZapisOdczyt::zapiszDrzewoBinarne(DrzewoBST& drzewo, const std::string& nazwa_pliku) {
    std::ofstream plik(nazwa_pliku, std::ios::binary);
    if (plik.is_open()) {
        drzewo.zapiszDoPliku(nazwa_pliku);
        plik.close();
    }
}

void ZapisOdczyt::wczytajDrzewoBinarne(DrzewoBST& drzewo, const std::string& nazwa_pliku) {
    std::ifstream plik(nazwa_pliku, std::ios::binary);
    int wartosc;
    while (plik >> wartosc) {
        drzewo.dodaj(wartosc);
    }
    plik.close();
}