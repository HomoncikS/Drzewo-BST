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

private:
    Wezel* korzen;

    Wezel* dodajRekurencyjnie(Wezel* wezel, int wartosc);
    Wezel* usunRekurencyjnie(Wezel* wezel, int wartosc);
    Wezel* znajdzMin(Wezel* wezel);
    void usunDrzewo(Wezel* wezel);
    bool szukajSciezkiRekurencyjnie(Wezel* wezel, int wartosc, std::vector<int>& sciezka);
};
#endif