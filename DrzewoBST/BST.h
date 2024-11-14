#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <fstream>
/// Definicja klasy DrzewoBST
class DrzewoBST {
public:
    /// Struktura wêz³a drzewa
    struct Wezel {
        /// Wartoœæ przechowywana w wêŸle
        int wartosc;    
        /// WskaŸnik na lewego potomka
        Wezel* lewy;   
        /// WskaŸnik na prawego potomka
        Wezel* prawy;  
        /// Konstruktor inicjalizuj¹cy wartoœæ
        Wezel(int wart) : wartosc(wart), lewy(nullptr), prawy(nullptr) {}   
    };

    /// Konstruktor inicjalizuj¹cy drzewo pustym korzeniem
    DrzewoBST() : korzen(nullptr) {}    
    /// Destruktor usuwaj¹cy drzewo
    ~DrzewoBST() { usunDrzewo(); }      
    
    /// Dodanie wartoœci do drzewa
    void dodaj(int wartosc);   
    /// Usuniêcie wartoœci z drzewa
    bool usun(int wartosc);     
    /// Usuniêcie ca³ego drzewa
    void usunDrzewo();          
    /// Szukanie œcie¿ki do wartoœci
    std::vector<int> szukajSciezki(int wartosc);   
    /// Wyœwietlanie drzewa w preorder
    void wyswietlPreOrder();        
    /// Wyœwietlanie drzewa w inorder
    void wyswietlInOrder();         
    /// Wyœwietlanie drzewa w postorder
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
    /// WskaŸnik na korzeñ drzewa
    Wezel* korzen;  
    /// Rekurencyjne dodawanie elementu do drzewa
    Wezel* dodajRekurencyjnie(Wezel* wezel, int wartosc);   
    /// Rekurencyjne usuwanie elementu z drzewa
    Wezel* usunRekurencyjnie(Wezel* wezel, int wartosc);    
    /// Znalezienie najmniejszego elementu w poddrzewie
    Wezel* znajdzMin(Wezel* wezel);                         
    /// Rekurencyjne usuwanie drzewa
    void usunDrzewo(Wezel* wezel);                        
    /// Rekurencyjne wyœwietlanie w preorder
    void wyswietlPreOrder(Wezel* wezel);        
    /// Rekurencyjne wyœwietlanie w inorder
    void wyswietlInOrder(Wezel* wezel);      
    /// Wyœwietlanie drzewa w postorder
    void wyswietlPostOrder(Wezel* wezel);                  
    /// Rekurencyjne zapisywanie do pliku tekstowego
    void zapiszDoPliku(Wezel* wezel, std::ofstream& plik);  
    /// Rekurencyjne zapisywanie do pliku binarnie
    void zapiszDoPlikuBinarnie(Wezel* wezel, std::ofstream& plik);     
    /// Rekurencyjne wczytywanie z pliku zapisanego binarnie
    Wezel* wczytajZPlikuBinarnie(std::ifstream& plik);                 

    /// Rekurencyjna metoda do szukania œcie¿ki do wêz³a o zadanej wartoœci.
    /// W trakcie przeszukiwania, dodaje odwiedzane wêz³y do wektora 'sciezka'.
    bool szukajSciezkiRekurencyjnie(Wezel* wezel, int wartosc, std::vector<int>& sciezka); 
    
};

#endif