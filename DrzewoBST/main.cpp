#include <iostream>
#include "BST.h"
#include "ZapisOdczyt.h"

/// Wyświetla menu
void wyswietlMenu() {
    std::cout << "1. Dodaj element\n";
    std::cout << "2. Usun element\n";
    std::cout << "3. Usun cale drzewo\n";
    std::cout << "4. Szukaj drogi do elementu\n";
    std::cout << "5. Wyswietl drzewo (preorder)\n";
    std::cout << "6. Wyswietl drzewo (inorder)\n";
    std::cout << "7. Wyswietl drzewo (postorder)\n";
    std::cout << "8. Zapisz drzewo do pliku\n";
    std::cout << "9. Wczytaj drzewo z pliku\n";
    std::cout << "10. Zapisz drzewo do pliku (binarny)\n";
    std::cout << "11. Wczytaj drzewo z pliku (binarny)\n";
    std::cout << "0. Wyjscie\n";    
}

int main() {
    DrzewoBST drzewo;     
    /// Zmienna przechowująca numer opcji w menu
    int wybor, wartosc;    
    /// Zmienna przechowująca nazwę pliku
    std::string nazwa_pliku; 
    /// Pętla do momentu wybrania opcji wyjścia
    while (true) {   
        /// Wyświetlenie menu
        wyswietlMenu();   
        /// Wczytanie wyboru opcji przez użytkownika
        std::cin >> wybor; 

        /// Obsługa opcji w menu
        switch (wybor) {  
        case 1:
            std::cout << "Podaj wartosc: ";
            /// Wczytanie wartości do dodania
            std::cin >> wartosc; 
            /// Dodanie elementu do drzewa
            drzewo.dodaj(wartosc); 
            break;
        case 2:
            std::cout << "Podaj wartosc do usuniecia: ";
            /// Wczytanie wartości do usunięcia
            std::cin >> wartosc; 
            /// Usunięcie elementu z drzewa
            drzewo.usun(wartosc);
            break;
        case 3:
            /// Usunięcie całego drzewa
            drzewo.usunDrzewo(); 
            break;
        case 4:
            std::cout << "Podaj wartosc, do ktorej chcesz znalezc droge: ";
            /// Wczytanie wartości do której szukamy drogi
            std::cin >> wartosc; 
            {
                /// Szukanie ścieżki do wartości
                std::vector<int> sciezka = drzewo.szukajSciezki(wartosc); 
                if (sciezka.empty()) {
                    /// Jeśli ścieżka pusta, element nie istnieje
                    std::cout << "Element nie znaleziony w drzewie.\n";  
                }
                else {
                    std::cout << "Droga do elementu: ";
                    for (int wart : sciezka) {
                        /// Wypisanie ścieżki
                        std::cout << wart << " "; 
                    }
                    std::cout << std::endl;
                }
            }
            break;
        case 5:
            /// Wyświetlenie drzewa w preorder
            drzewo.wyswietlPreOrder();  
            break;
        case 6:
            /// Wyświetlenie drzewa w inorder
            drzewo.wyswietlInOrder();   
            break;
        case 7:
            /// Wyświetlenie drzewa w postorder
            drzewo.wyswietlPostOrder(); 
            break;
        case 8:
            std::cout << "Podaj nazwe pliku: ";
            /// Wczytanie nazwy pliku
            std::cin >> nazwa_pliku;    
            /// Zapis drzewa do pliku tekstowego
            drzewo.zapiszDoPliku(nazwa_pliku);  
            break;
        case 9:
            std::cout << "Podaj nazwe pliku: ";
            /// Wczytanie nazwy pliku
            std::cin >> nazwa_pliku;    
            /// Wczytanie drzewa z pliku tekstowego
            ZapisOdczyt::wczytajDrzewoBinarne(drzewo, nazwa_pliku); 
            break;
        case 10:
            std::cout << "Podaj nazwe pliku do zapisu (binarny): ";
            /// Wczytanie nazwy pliku
            std::cin >> nazwa_pliku;    
            /// Zapis drzewa do pliku binarnie
            drzewo.zapiszDoPlikuBinarnie(nazwa_pliku); 
            break;
        case 11:
            std::cout << "Podaj nazwe pliku do odczytu (binarny): ";
            /// Wczytanie nazwy pliku
            std::cin >> nazwa_pliku;    
            /// Wczytanie drzewa z pliku zapisanego binarnie
            drzewo.wczytajZPlikuBinarnie(nazwa_pliku); 
            break;
        case 0:
            /// Zakończenie programu
            return 0; 
        }
    }
}