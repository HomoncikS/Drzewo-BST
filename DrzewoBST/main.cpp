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
    int wybor, wartosc;
    std::string nazwa_pliku;

    while (true) {
        wyswietlMenu();
        std::cin >> wybor;

        switch (wybor) {
        case 1:
            std::cout << "Podaj wartosc: ";
            std::cin >> wartosc;
            drzewo.dodaj(wartosc);
            break;
        case 2:
            std::cout << "Podaj wartosc do usuniecia: ";
            std::cin >> wartosc;
            drzewo.usun(wartosc);
            break;
        case 3:
            drzewo.usunDrzewo();
            break;
        case 4:
            std::cout << "Podaj wartosc, do ktorej chcesz znalezc droge: ";
            std::cin >> wartosc;
            {
                std::vector<int> sciezka = drzewo.szukajSciezki(wartosc);
                if (sciezka.empty()) {
                    std::cout << "Element nie znaleziony w drzewie.\n";
                }
                else {
                    std::cout << "Droga do elementu: ";
                    for (int wart : sciezka) {
                        std::cout << wart << " ";
                    }
                    std::cout << std::endl;
                }
            }
            break;
        case 5:
            drzewo.wyswietlPreOrder();
            break;
        case 6:
            drzewo.wyswietlInOrder();
            break;
        case 7:
            drzewo.wyswietlPostOrder();
            break;
        case 8:
            std::cout << "Podaj nazwe pliku: ";
            std::cin >> nazwa_pliku;
            drzewo.zapiszDoPliku(nazwa_pliku);
            break;
        case 9:
            std::cout << "Podaj nazwe pliku: ";
            std::cin >> nazwa_pliku;
            ZapisOdczyt::wczytajDrzewoBinarne(drzewo, nazwa_pliku);
            break;
        case 10:
            std::cout << "Podaj nazwe pliku do zapisu (binarny): ";
            std::cin >> nazwa_pliku;
            drzewo.zapiszDoPlikuBinarnego(nazwa_pliku);
            break;
        case 11:
            std::cout << "Podaj nazwe pliku do odczytu (binarny): ";
            std::cin >> nazwa_pliku;
            drzewo.wczytajZPlikuBinarnego(nazwa_pliku);
            break;
        case 0:
            return 0;
        }
    }
}