#include "ZapisOdczyt.h"
#include <fstream>

// Funkcja zapisuje drzewo BST do pliku w formacie binarnym
void ZapisOdczyt::zapiszDrzewoBinarne(DrzewoBST& drzewo, const std::string& nazwa_pliku) {
    // Otwórz plik do zapisu w trybie binarnym
    std::ofstream plik(nazwa_pliku, std::ios::binary);

    // SprawdŸ, czy plik zosta³ poprawnie otwarty
    if (plik.is_open()) {
        // Wywo³aj metodê zapisu drzewa do pliku w drzewie BST (w pliku binarnym)
        drzewo.zapiszDoPliku(nazwa_pliku);
        plik.close();  // Zamknij plik po zapisaniu
    }
    // Jeœli plik nie mo¿e zostaæ otwarty, funkcja nie wykona ¿adnej akcji
}

// Funkcja wczytuje drzewo BST z pliku binarnego
void ZapisOdczyt::wczytajDrzewoBinarne(DrzewoBST& drzewo, const std::string& nazwa_pliku) {
    // Otwórz plik do odczytu w trybie binarnym
    std::ifstream plik(nazwa_pliku, std::ios::binary);

    int wartosc;
    // Wczytuj wartoœci z pliku, a¿ osi¹gniesz koniec
    while (plik >> wartosc) {
        // Dodaj wczytan¹ wartoœæ do drzewa BST
        drzewo.dodaj(wartosc);
    }
    plik.close();  // Zamknij plik po odczycie
}