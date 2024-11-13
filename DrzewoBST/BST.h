#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <fstream>

class DrzewoBST {
public:
    struct Wezel {
        int wartosc;
        Wezel* lewy;
        Wezel* prawy;
        Wezel(int wart) : wartosc(wart), lewy(nullptr), prawy(nullptr) {}
    };

    DrzewoBST() : korzen(nullptr) {}
    ~DrzewoBST() { usunDrzewo(); }

    void dodaj(int wartosc);
    bool usun(int wartosc);
    void usunDrzewo();
    std::vector<int> szukajSciezki(int wartosc);
    void wyswietlPreOrder();
    void wyswietlInOrder();
    void wyswietlPostOrder();
    void zapiszDoPliku(const std::string& nazwa_pliku);
    void wczytajZPliku(const std::string& nazwa_pliku);
    void zapiszDoPlikuBinarnego(const std::string& nazwa_pliku);
    void wczytajZPlikuBinarnego(const std::string& nazwa_pliku);

private:
    Wezel* korzen;

    Wezel* dodajRekurencyjnie(Wezel* wezel, int wartosc);
    Wezel* usunRekurencyjnie(Wezel* wezel, int wartosc);
    Wezel* znajdzMin(Wezel* wezel);
    void usunDrzewo(Wezel* wezel);
    void wyswietlPreOrder(Wezel* wezel);
    void wyswietlInOrder(Wezel* wezel);
    void wyswietlPostOrder(Wezel* wezel);
    void zapiszDoPliku(Wezel* wezel, std::ofstream& plik);
    void zapiszDoPlikuBinarnego(Wezel* wezel, std::ofstream& plik);
    Wezel* wczytajZPlikuBinarnego(std::ifstream& plik);

    bool szukajSciezkiRekurencyjnie(Wezel* wezel, int wartosc, std::vector<int>& sciezka);
};

#endif