#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <fstream>
// Definicja klasy DrzewoBST
class DrzewoBST {
public:
    // Struktura w�z�a drzewa
    struct Wezel {
        int wartosc;    // Warto�� przechowywana w w�le
        Wezel* lewy;   // Wska�nik na lewego potomka
        Wezel* prawy;  // Wska�nik na prawego potomka
        Wezel(int wart) : wartosc(wart), lewy(nullptr), prawy(nullptr) {}   // Konstruktor inicjalizuj�cy warto��
    };

    DrzewoBST() : korzen(nullptr) {}    // Konstruktor inicjalizuj�cy drzewo pustym korzeniem
    ~DrzewoBST() { usunDrzewo(); }      // Destruktor usuwaj�cy drzewo

    void dodaj(int wartosc);    // Dodanie warto�ci do drzewa
    bool usun(int wartosc);     // Usuni�cie warto�ci z drzewa
    void usunDrzewo();          // Usuni�cie ca�ego drzewa
    std::vector<int> szukajSciezki(int wartosc);    // Szukanie �cie�ki do warto�ci
    void wyswietlPreOrder();        // Wy�wietlanie drzewa w preorder
    void wyswietlInOrder();         // Wy�wietlanie drzewa w inorder
    void wyswietlPostOrder();       // Wy�wietlanie drzewa w postorder
    void zapiszDoPliku(const std::string& nazwa_pliku);     // Zapis drzewa do pliku tekstowego
    void wczytajZPliku(const std::string& nazwa_pliku);     // Wczytanie drzewa z pliku tekstowego
    void zapiszDoPlikuBinarnie(const std::string& nazwa_pliku);    // Zapis drzewa do pliku binarnie
    void wczytajZPlikuBinarnie(const std::string& nazwa_pliku);    // Wczytanie drzewa z pliku binarnie

private:
    Wezel* korzen;  // Wska�nik na korze� drzewa

    Wezel* dodajRekurencyjnie(Wezel* wezel, int wartosc);   // Rekurencyjne dodawanie elementu do drzewa
    Wezel* usunRekurencyjnie(Wezel* wezel, int wartosc);    // Rekurencyjne usuwanie elementu z drzewa
    Wezel* znajdzMin(Wezel* wezel);                         // Znalezienie najmniejszego elementu w poddrzewie
    void usunDrzewo(Wezel* wezel);                          // Rekurencyjne usuwanie drzewa
    void wyswietlPreOrder(Wezel* wezel);                    // Rekurencyjne wy�wietlanie w preorder
    void wyswietlInOrder(Wezel* wezel);                     // Rekurencyjne wy�wietlanie w inorder
    void wyswietlPostOrder(Wezel* wezel);                   // Wy�wietlanie drzewa w postorder
    void zapiszDoPliku(Wezel* wezel, std::ofstream& plik);  // Rekurencyjne zapisywanie do pliku tekstowego
    void zapiszDoPlikuBinarnie(Wezel* wezel, std::ofstream& plik);     // Rekurencyjne zapisywanie do pliku binarnie
    Wezel* wczytajZPlikuBinarnie(std::ifstream& plik);                 // Rekurencyjne wczytywanie z pliku zapisanego binarnie

    bool szukajSciezkiRekurencyjnie(Wezel* wezel, int wartosc, std::vector<int>& sciezka); 
    // Rekurencyjna metoda do szukania �cie�ki do w�z�a o zadanej warto�ci.
    // W trakcie przeszukiwania, dodaje odwiedzane w�z�y do wektora 'sciezka'.
};

#endif