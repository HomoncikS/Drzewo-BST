#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <fstream>
// Definicja klasy DrzewoBST
class DrzewoBST {
public:
    // Struktura wêz³a drzewa
    struct Wezel {
        int wartosc;    // Wartoœæ przechowywana w wêŸle
        Wezel* lewy;   // WskaŸnik na lewego potomka
        Wezel* prawy;  // WskaŸnik na prawego potomka
        Wezel(int wart) : wartosc(wart), lewy(nullptr), prawy(nullptr) {}   // Konstruktor inicjalizuj¹cy wartoœæ
    };

    DrzewoBST() : korzen(nullptr) {}    // Konstruktor inicjalizuj¹cy drzewo pustym korzeniem
    ~DrzewoBST() { usunDrzewo(); }      // Destruktor usuwaj¹cy drzewo

    void dodaj(int wartosc);    // Dodanie wartoœci do drzewa
    bool usun(int wartosc);     // Usuniêcie wartoœci z drzewa
    void usunDrzewo();          // Usuniêcie ca³ego drzewa
    std::vector<int> szukajSciezki(int wartosc);    // Szukanie œcie¿ki do wartoœci
    void wyswietlPreOrder();        // Wyœwietlanie drzewa w preorder
    void wyswietlInOrder();         // Wyœwietlanie drzewa w inorder
    void wyswietlPostOrder();       // Wyœwietlanie drzewa w postorder
    void zapiszDoPliku(const std::string& nazwa_pliku);     // Zapis drzewa do pliku tekstowego
    void wczytajZPliku(const std::string& nazwa_pliku);     // Wczytanie drzewa z pliku tekstowego
    void zapiszDoPlikuBinarnie(const std::string& nazwa_pliku);    // Zapis drzewa do pliku binarnie
    void wczytajZPlikuBinarnie(const std::string& nazwa_pliku);    // Wczytanie drzewa z pliku binarnie

private:
    Wezel* korzen;  // WskaŸnik na korzeñ drzewa

    Wezel* dodajRekurencyjnie(Wezel* wezel, int wartosc);   // Rekurencyjne dodawanie elementu do drzewa
    Wezel* usunRekurencyjnie(Wezel* wezel, int wartosc);    // Rekurencyjne usuwanie elementu z drzewa
    Wezel* znajdzMin(Wezel* wezel);                         // Znalezienie najmniejszego elementu w poddrzewie
    void usunDrzewo(Wezel* wezel);                          // Rekurencyjne usuwanie drzewa
    void wyswietlPreOrder(Wezel* wezel);                    // Rekurencyjne wyœwietlanie w preorder
    void wyswietlInOrder(Wezel* wezel);                     // Rekurencyjne wyœwietlanie w inorder
    void wyswietlPostOrder(Wezel* wezel);                   // Wyœwietlanie drzewa w postorder
    void zapiszDoPliku(Wezel* wezel, std::ofstream& plik);  // Rekurencyjne zapisywanie do pliku tekstowego
    void zapiszDoPlikuBinarnie(Wezel* wezel, std::ofstream& plik);     // Rekurencyjne zapisywanie do pliku binarnie
    Wezel* wczytajZPlikuBinarnie(std::ifstream& plik);                 // Rekurencyjne wczytywanie z pliku zapisanego binarnie

    bool szukajSciezkiRekurencyjnie(Wezel* wezel, int wartosc, std::vector<int>& sciezka); 
    // Rekurencyjna metoda do szukania œcie¿ki do wêz³a o zadanej wartoœci.
    // W trakcie przeszukiwania, dodaje odwiedzane wêz³y do wektora 'sciezka'.
};

#endif