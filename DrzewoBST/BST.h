#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <fstream>
/// Definicja klasy DrzewoBST
class DrzewoBST {
public:
    /// Struktura w�z�a drzewa
    struct Wezel {
        /// Warto�� przechowywana w w�le
        int wartosc;    
        /// Wska�nik na lewego potomka
        Wezel* lewy;   
        /// Wska�nik na prawego potomka
        Wezel* prawy;  
        /// Konstruktor inicjalizuj�cy warto��
        Wezel(int wart) : wartosc(wart), lewy(nullptr), prawy(nullptr) {}   
    };

    /// Konstruktor inicjalizuj�cy drzewo pustym korzeniem
    DrzewoBST() : korzen(nullptr) {}    
    /// Destruktor usuwaj�cy drzewo
    ~DrzewoBST() { usunDrzewo(); }      
    
    /// Dodanie warto�ci do drzewa
    void dodaj(int wartosc);   
    /// Usuni�cie warto�ci z drzewa
    bool usun(int wartosc);     
    /// Usuni�cie ca�ego drzewa
    void usunDrzewo();          
    /// Szukanie �cie�ki do warto�ci
    std::vector<int> szukajSciezki(int wartosc);   
    /// Wy�wietlanie drzewa w preorder
    void wyswietlPreOrder();        
    /// Wy�wietlanie drzewa w inorder
    void wyswietlInOrder();         
    /// Wy�wietlanie drzewa w postorder
    void wyswietlPostOrder();      
    /// Zapis drzewa do pliku tekstowego
    void zapiszDoPliku(const std::string& nazwa_pliku);     
    /// Wczytanie drzewa z pliku tekstowego
    void wczytajZPliku(const std::string& nazwa_pliku);     
    /// Zapis drzewa do pliku binarnie
    void zapiszDoPlikuBinarnie(const std::string& nazwa_pliku);   
    /// Wczytanie drzewa z pliku binarnie
    void wczytajZPlikuBinarnie(const std::string& nazwa_pliku);    

private:
    /// Wska�nik na korze� drzewa
    Wezel* korzen;  
    /// Rekurencyjne dodawanie elementu do drzewa
    Wezel* dodajRekurencyjnie(Wezel* wezel, int wartosc);   
    /// Rekurencyjne usuwanie elementu z drzewa
    Wezel* usunRekurencyjnie(Wezel* wezel, int wartosc);    
    /// Znalezienie najmniejszego elementu w poddrzewie
    Wezel* znajdzMin(Wezel* wezel);                         
    /// Rekurencyjne usuwanie drzewa
    void usunDrzewo(Wezel* wezel);                        
    /// Rekurencyjne wy�wietlanie w preorder
    void wyswietlPreOrder(Wezel* wezel);        
    /// Rekurencyjne wy�wietlanie w inorder
    void wyswietlInOrder(Wezel* wezel);      
    /// Wy�wietlanie drzewa w postorder
    void wyswietlPostOrder(Wezel* wezel);                  
    /// Rekurencyjne zapisywanie do pliku tekstowego
    void zapiszDoPliku(Wezel* wezel, std::ofstream& plik);  
    /// Rekurencyjne zapisywanie do pliku binarnie
    void zapiszDoPlikuBinarnie(Wezel* wezel, std::ofstream& plik);     
    /// Rekurencyjne wczytywanie z pliku zapisanego binarnie
    Wezel* wczytajZPlikuBinarnie(std::ifstream& plik);                 

    /// Rekurencyjna metoda do szukania �cie�ki do w�z�a o zadanej warto�ci.
    /// W trakcie przeszukiwania, dodaje odwiedzane w�z�y do wektora 'sciezka'.
    bool szukajSciezkiRekurencyjnie(Wezel* wezel, int wartosc, std::vector<int>& sciezka); 
    
};

#endif