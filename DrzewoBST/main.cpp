#include <iostream>
#include "BST.h"

/// Wyświetlenie menu
void wyswietlMenu() {
    std::cout << "1. Dodaj element\n";
    std::cout << "2. Usun element\n";
    std::cout << "3. Usun cale drzewo\n";
    std::cout << "4. Szukaj drogi do elementu\n";
    std::cout << "5. Wyswietl drzewo (preorder)\n";
    std::cout << "6. Wyswietl drzewo (inorder)\n";
    std::cout << "7. Wyswietl drzewo (postorder)\n";
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
            case 5:
                drzewo.wyswietlPreOrder();
                break;
            case 6:
                drzewo.wyswietlInOrder();
                break;
            case 7:
                drzewo.wyswietlPostOrder();
                break;
                break;
            case 0:
                return 0;
            }
        }
    }
