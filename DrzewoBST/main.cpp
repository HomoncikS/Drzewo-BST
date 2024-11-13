#include <iostream>
#include "BST.h"
#include "ZapisOdczyt.h"


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
    int wybor, wartosc;    // Zmienna przechowująca numer opcji w menu
    std::string nazwa_pliku; // Zmienna przechowująca nazwę pliku

    while (true) {   // Pętla do momentu wybrania opcji wyjścia
        wyswietlMenu();   // Wyświetlenie menu
        std::cin >> wybor; // Wczytanie wyboru opcji przez użytkownika

        switch (wybor) {  // Obsługa opcji w menu
        case 1:
            std::cout << "Podaj wartosc: ";
            std::cin >> wartosc; // Wczytanie wartości do dodania
            drzewo.dodaj(wartosc); // Dodanie elementu do drzewa
            break;
        case 2:
            std::cout << "Podaj wartosc do usuniecia: ";
            std::cin >> wartosc; // Wczytanie wartości do usunięcia
            drzewo.usun(wartosc); // Usunięcie elementu z drzewa
            break;
        case 3:
            drzewo.usunDrzewo(); // Usunięcie całego drzewa
            break;
        case 4:
            std::cout << "Podaj wartosc, do ktorej chcesz znalezc droge: ";
            std::cin >> wartosc; // Wczytanie wartości do której szukamy drogi
            {
                std::vector<int> sciezka = drzewo.szukajSciezki(wartosc); // Szukanie ścieżki do wartości
                if (sciezka.empty()) {
                    std::cout << "Element nie znaleziony w drzewie.\n";  // Jeśli ścieżka pusta, element nie istnieje
                }
                else {
                    std::cout << "Droga do elementu: ";
                    for (int wart : sciezka) {
                        std::cout << wart << " "; // Wypisanie ścieżki
                    }
                    std::cout << std::endl;
                }
            }
            break;
        case 5:
            drzewo.wyswietlPreOrder();  // Wyświetlenie drzewa w preorder
            break;
        case 6:
            drzewo.wyswietlInOrder();   // Wyświetlenie drzewa w inorder
            break;
        case 7:
            drzewo.wyswietlPostOrder(); // Wyświetlenie drzewa w postorder
            break;
        case 8:
            std::cout << "Podaj nazwe pliku: ";
            std::cin >> nazwa_pliku;    // Wczytanie nazwy pliku
            drzewo.zapiszDoPliku(nazwa_pliku);  // Zapis drzewa do pliku tekstowego
            break;
        case 9:
            std::cout << "Podaj nazwe pliku: ";
            std::cin >> nazwa_pliku;    // Wczytanie nazwy pliku
            ZapisOdczyt::wczytajDrzewoBinarne(drzewo, nazwa_pliku);  // Wczytanie drzewa z pliku tekstowego
            break;
        case 10:
            std::cout << "Podaj nazwe pliku do zapisu (binarny): ";
            std::cin >> nazwa_pliku;    // Wczytanie nazwy pliku
            drzewo.zapiszDoPlikuBinarnie(nazwa_pliku); // Zapis drzewa do pliku binarnie
            break;
        case 11:
            std::cout << "Podaj nazwe pliku do odczytu (binarny): ";
            std::cin >> nazwa_pliku;    // Wczytanie nazwy pliku
            drzewo.wczytajZPlikuBinarnie(nazwa_pliku); // Wczytanie drzewa z pliku zapisanego binarnie
            break;
        case 0:
            return 0; // Zakończenie programu
        }
    }
}