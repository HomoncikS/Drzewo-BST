#include <iostream>
#include "BST.h"

void wyswietlMenu() {
    std::cout << "1. Dodaj element\n";
    std::cout << "2. Usun element\n";
    std::cout << "3. Usun cale drzewo\n";
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
            case 0:
                return 0;
            }
        }
    }