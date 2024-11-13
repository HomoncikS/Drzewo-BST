#include "ZapisOdczyt.h"
#include <fstream>

// Funkcja zapisuje drzewo BST do pliku w formacie binarnym
void ZapisOdczyt::zapiszDrzewoBinarne(DrzewoBST& drzewo, const std::string& nazwa_pliku) {
    // Otw�rz plik do zapisu w trybie binarnym
    std::ofstream plik(nazwa_pliku, std::ios::binary);

    // Sprawd�, czy plik zosta� poprawnie otwarty
    if (plik.is_open()) {
        // Wywo�aj metod� zapisu drzewa do pliku w drzewie BST (w pliku binarnym)
        drzewo.zapiszDoPliku(nazwa_pliku);
        plik.close();  // Zamknij plik po zapisaniu
    }
    // Je�li plik nie mo�e zosta� otwarty, funkcja nie wykona �adnej akcji
}

// Funkcja wczytuje drzewo BST z pliku binarnego
void ZapisOdczyt::wczytajDrzewoBinarne(DrzewoBST& drzewo, const std::string& nazwa_pliku) {
    // Otw�rz plik do odczytu w trybie binarnym
    std::ifstream plik(nazwa_pliku, std::ios::binary);

    int wartosc;
    // Wczytuj warto�ci z pliku, a� osi�gniesz koniec
    while (plik >> wartosc) {
        // Dodaj wczytan� warto�� do drzewa BST
        drzewo.dodaj(wartosc);
    }
    plik.close();  // Zamknij plik po odczycie
}