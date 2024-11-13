#include "BST.h"

// Dodaje nowy wêze³ o zadanej wartoœci do drzewa BST
void DrzewoBST::dodaj(int wartosc) {
    korzen = dodajRekurencyjnie(korzen, wartosc);  // Rozpoczyna dodawanie rekurencyjnie od korzenia
}

// Rekurencyjna pomocnicza funkcja do dodawania nowego wêz³a do drzewa BST
DrzewoBST::Wezel* DrzewoBST::dodajRekurencyjnie(Wezel* wezel, int wartosc) {
    if (!wezel) return new Wezel(wartosc);  // Jeœli wêze³ jest pusty, twórz nowy wêze³
    if (wartosc < wezel->wartosc) {  // Jeœli wartoœæ jest mniejsza, dodaj do lewego poddrzewa
        wezel->lewy = dodajRekurencyjnie(wezel->lewy, wartosc);
    }
    else if (wartosc > wezel->wartosc) {  // Jeœli wartoœæ jest wiêksza, dodaj do prawego poddrzewa
        wezel->prawy = dodajRekurencyjnie(wezel->prawy, wartosc);
    }
    return wezel;  // Zwróæ wêze³
}

// Usuwa wêze³ o zadanej wartoœci z drzewa
bool DrzewoBST::usun(int wartosc) {
    korzen = usunRekurencyjnie(korzen, wartosc);  // Wywo³aj funkcjê usuwania rekurencyjnie
    return korzen != nullptr;  // Zwróæ true, jeœli drzewo nie jest puste po usuniêciu
}

// Rekurencyjna pomocnicza funkcja do usuwania wêz³a w drzewie
DrzewoBST::Wezel* DrzewoBST::usunRekurencyjnie(Wezel* wezel, int wartosc) {
    if (!wezel) return nullptr;  // Jeœli wêze³ jest pusty, zakoñcz
    if (wartosc < wezel->wartosc) {  // Jeœli wartoœæ jest mniejsza, usuñ rekurencyjnie z lewego poddrzewa
        wezel->lewy = usunRekurencyjnie(wezel->lewy, wartosc);
    }
    else if (wartosc > wezel->wartosc) {  // Jeœli wartoœæ jest wiêksza, usuñ rekurencyjnie z prawego poddrzewa
        wezel->prawy = usunRekurencyjnie(wezel->prawy, wartosc);
    }
    else {  // Jeœli znaleziono wêze³ do usuniêcia
        if (!wezel->lewy) {  // Jeœli wêze³ nie ma lewego dziecka, zast¹p go prawym dzieckiem
            Wezel* temp = wezel->prawy;
            delete wezel;
            return temp;
        }
        else if (!wezel->prawy) {  // Jeœli wêze³ nie ma prawego dziecka, zast¹p go lewym dzieckiem
            Wezel* temp = wezel->lewy;
            delete wezel;
            return temp;
        }
        // W przypadku wêz³a z dwoma dzieæmi, znajdŸ najmniejszy wêze³ w prawym poddrzewie
        Wezel* minWezel = znajdzMin(wezel->prawy);
        wezel->wartosc = minWezel->wartosc;  // Zamieñ wartoœæ wêz³a z najmniejszym wêz³em
        wezel->prawy = usunRekurencyjnie(wezel->prawy, minWezel->wartosc);  // Usuñ najmniejszy wêze³
    }
    return wezel;  // Zwróæ nowy wêze³ po usuniêciu
}

// Zwraca wêze³ o najmniejszej wartoœci w danym poddrzewie
DrzewoBST::Wezel* DrzewoBST::znajdzMin(Wezel* wezel) {
    while (wezel && wezel->lewy) wezel = wezel->lewy;  // PrzejdŸ do najdalej po³o¿onego lewego wêz³a
    return wezel;  // Zwróæ wêze³ o najmniejszej wartoœci
}

// Szuka œcie¿ki do wêz³a o zadanej wartoœci w drzewie
std::vector<int> DrzewoBST::szukajSciezki(int wartosc) {
    std::vector<int> sciezka;
    if (szukajSciezkiRekurencyjnie(korzen, wartosc, sciezka)) {
        return sciezka;  // Jeœli œcie¿ka zosta³a znaleziona, zwróæ j¹
    }
    else {
        return {};  // Zwróæ pusty wektor, jeœli element nie zosta³ znaleziony
    }
}

// Rekurencyjna funkcja do szukania œcie¿ki do wêz³a o zadanej wartoœci
bool DrzewoBST::szukajSciezkiRekurencyjnie(Wezel* wezel, int wartosc, std::vector<int>& sciezka) {
    if (!wezel) return false;  // Jeœli wêze³ jest pusty, zakoñcz
    sciezka.push_back(wezel->wartosc);  // Dodaj wartoœæ wêz³a do œcie¿ki
    if (wezel->wartosc == wartosc) {
        return true;  // Jeœli znaleziono wêze³, zakoñcz
    }
    // Rekurencyjnie sprawdzaj lewego lub prawego potomka w zale¿noœci od wartoœci
    if (wartosc < wezel->wartosc) {
        return szukajSciezkiRekurencyjnie(wezel->lewy, wartosc, sciezka);
    }
    else {
        return szukajSciezkiRekurencyjnie(wezel->prawy, wartosc, sciezka);
    }
}

// Usuwa ca³e drzewo BST
void DrzewoBST::usunDrzewo() {
    usunDrzewo(korzen);  // Wywo³aj funkcjê usuwania rekurencyjnie dla korzenia
    korzen = nullptr;  // Ustaw korzeñ na nullptr po usuniêciu ca³ego drzewa
}

// Rekurencyjna funkcja do usuwania ca³ego drzewa
void DrzewoBST::usunDrzewo(Wezel* wezel) {
    if (wezel) {
        usunDrzewo(wezel->lewy);  // Usuñ lewe poddrzewo
        usunDrzewo(wezel->prawy);  // Usuñ prawe poddrzewo
        delete wezel;  // Usuñ bie¿¹cy wêze³
    }
}

// Wypisuje wartoœci wêz³ów w drzewie w porz¹dku pre-order
void DrzewoBST::wyswietlPreOrder() {
    wyswietlPreOrder(korzen);  // Wywo³aj funkcjê rekurencyjnie dla korzenia
    std::cout << std::endl;
}

// Rekurencyjna funkcja do wypisywania w porz¹dku pre-order
void DrzewoBST::wyswietlPreOrder(Wezel* wezel) {
    if (wezel) {
        std::cout << wezel->wartosc << " ";  // Wypisz wartoœæ bie¿¹cego wêz³a
        wyswietlPreOrder(wezel->lewy);  // Wypisz lewe poddrzewo
        wyswietlPreOrder(wezel->prawy);  // Wypisz prawe poddrzewo
    }
}

// Wypisuje wartoœci wêz³ów w drzewie w porz¹dku in-order
void DrzewoBST::wyswietlInOrder() {
    wyswietlInOrder(korzen);  // Wywo³aj funkcjê rekurencyjnie dla korzenia
    std::cout << std::endl;
}

// Rekurencyjna funkcja do wypisywania w porz¹dku in-order
void DrzewoBST::wyswietlInOrder(Wezel* wezel) {
    if (wezel) {
        wyswietlInOrder(wezel->lewy);  // Wypisz lewe poddrzewo
        std::cout << wezel->wartosc << " ";  // Wypisz wartoœæ bie¿¹cego wêz³a
        wyswietlInOrder(wezel->prawy);  // Wypisz prawe poddrzewo
    }
}

// Wypisuje wartoœci wêz³ów w drzewie w porz¹dku post-order
void DrzewoBST::wyswietlPostOrder() {
    wyswietlPostOrder(korzen);  // Wywo³aj funkcjê rekurencyjnie dla korzenia
    std::cout << std::endl;
}

// Rekurencyjna funkcja do wypisywania w porz¹dku post-order
void DrzewoBST::wyswietlPostOrder(Wezel* wezel) {
    if (wezel) {
        wyswietlPostOrder(wezel->lewy);  // Wypisz lewe poddrzewo
        wyswietlPostOrder(wezel->prawy);  // Wypisz prawe poddrzewo
        std::cout << wezel->wartosc << " ";  // Wypisz wartoœæ bie¿¹cego wêz³a
    }
}

// Zapisuje drzewo do pliku tekstowego
void DrzewoBST::zapiszDoPliku(const std::string& nazwa_pliku) {
    std::ofstream plik(nazwa_pliku);  // Otwórz plik do zapisu
    if (plik.is_open()) {
        zapiszDoPliku(korzen, plik);  // Zapisz drzewo rekurencyjnie od korzenia
        plik.close();
    }
}

// Rekurencyjna funkcja do zapisywania drzewa do pliku tekstowego
void DrzewoBST::zapiszDoPliku(Wezel* wezel, std::ofstream& plik) {
    if (wezel) {
        plik << wezel->wartosc << " ";  // Zapisz wartoœæ wêz³a
        zapiszDoPliku(wezel->lewy, plik);  // Zapisz lewe poddrzewo
        zapiszDoPliku(wezel->prawy, plik);  // Zapisz prawe poddrzewo
    }
}

// Zapisuje drzewo do pliku binarnie
void DrzewoBST::zapiszDoPlikuBinarnie(const std::string& nazwa_pliku) {
    std::ofstream plik(nazwa_pliku, std::ios::binary);  // Otwórz plik do zapisu
    if (plik.is_open()) {
        zapiszDoPlikuBinarnie(korzen, plik);  // Zapisz drzewo binarnie
        plik.close();
    }
    else {
        std::cerr << "Nie mozna otworzyc pliku do zapisu binarnego.\n";
    }
}

// Rekurencyjna funkcja do zapisywania drzewa do pliku binarnie
void DrzewoBST::zapiszDoPlikuBinarnie(Wezel* wezel, std::ofstream& plik) {
    if (wezel) {
        plik.write(reinterpret_cast<const char*>(&wezel->wartosc), sizeof(wezel->wartosc));  // Zapisz wartoœæ wêz³a
        bool maLewy = (wezel->lewy != nullptr);  // SprawdŸ, czy wêze³ ma lewe dziecko
        bool maPrawy = (wezel->prawy != nullptr);  // SprawdŸ, czy wêze³ ma prawe dziecko
        plik.write(reinterpret_cast<const char*>(&maLewy), sizeof(maLewy));  // Zapisz, czy ma lewe dziecko
        plik.write(reinterpret_cast<const char*>(&maPrawy), sizeof(maPrawy));  // Zapisz, czy ma prawe dziecko
        if (wezel->lewy) zapiszDoPlikuBinarnie(wezel->lewy, plik);  // Zapisz lewe poddrzewo
        if (wezel->prawy) zapiszDoPlikuBinarnie(wezel->prawy, plik);  // Zapisz prawe poddrzewo
    }
}

// Wczytuje drzewo z pliku zapisanego binarnie
void DrzewoBST::wczytajZPlikuBinarnie(const std::string& nazwa_pliku) {
    std::ifstream plik(nazwa_pliku, std::ios::binary);  // Otwórz plik zapisany binarnie do odczytu
    if (plik.is_open()) {
        usunDrzewo();  // Usuñ istniej¹ce drzewo przed wczytaniem nowego
        korzen = wczytajZPlikuBinarnie(plik);  // Wczytaj drzewo z pliku
        plik.close();
    }
    else {
        std::cerr << "Nie mozna otworzyc pliku do odczytu binarnego.\n";
    }
}

// Rekurencyjna funkcja do wczytywania drzewa z pliku zapisanego binarnie
DrzewoBST::Wezel* DrzewoBST::wczytajZPlikuBinarnie(std::ifstream& plik) {
    int wartosc;
    bool maLewy, maPrawy;
    if (!plik.read(reinterpret_cast<char*>(&wartosc), sizeof(wartosc))) {
        return nullptr;  // Zakoñcz, jeœli koniec pliku
    }
    Wezel* wezel = new Wezel(wartosc);  // Utwórz nowy wêze³
    plik.read(reinterpret_cast<char*>(&maLewy), sizeof(maLewy));  // Wczytaj, czy wêze³ ma lewe dziecko
    plik.read(reinterpret_cast<char*>(&maPrawy), sizeof(maPrawy));  // Wczytaj, czy wêze³ ma prawe dziecko
    if (maLewy) {
        wezel->lewy = wczytajZPlikuBinarnie(plik);  // Wczytaj lewe poddrzewo
    }
    if (maPrawy) {
        wezel->prawy = wczytajZPlikuBinarnie(plik);  // Wczytaj prawe poddrzewo
    }
    return wezel;  // Zwróæ wêze³
}