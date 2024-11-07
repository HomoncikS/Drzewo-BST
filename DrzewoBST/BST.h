#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <fstream>

/// Klasa DrzewoBST
class DrzewoBST {
public:
    /// struktura wezel
    struct Wezel {
        int wartosc;
        Wezel* lewy;
        Wezel* prawy;
        Wezel(int wart) : wartosc(wart), lewy(nullptr), prawy(nullptr) {}
    };
    
    /// @brief konstruktor
    DrzewoBST() : korzen(nullptr) {}
    /// @brief destruktor
    ~DrzewoBST() { usunDrzewo(); }

    void dodaj(int wartosc);
    bool usun(int wartosc);
    void usunDrzewo();
    std::vector<int> szukajSciezki(int wartosc);
    void wyswietlPreOrder();
    void wyswietlInOrder();
    void wyswietlPostOrder();

private:
    Wezel* korzen;

    Wezel* dodajRekurencyjnie(Wezel* wezel, int wartosc);
    Wezel* usunRekurencyjnie(Wezel* wezel, int wartosc);
    Wezel* znajdzMin(Wezel* wezel);
    void usunDrzewo(Wezel* wezel);
    bool szukajSciezkiRekurencyjnie(Wezel* wezel, int wartosc, std::vector<int>& sciezka);
    void wyswietlPreOrder(Wezel* wezel);
    void wyswietlInOrder(Wezel* wezel);
    void wyswietlPostOrder(Wezel* wezel);
};
#endif