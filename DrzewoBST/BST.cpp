#include "BST.h"

/// Dodaje nowy wêze³ o zadanej wartoœci do drzewa BST
void DrzewoBST::dodaj(int wartosc) {
    korzen = dodajRekurencyjnie(korzen, wartosc);  // Rozpoczyna dodawanie rekurencyjnie od korzenia
}

/// Rekurencyjna pomocnicza funkcja do dodawania nowego wêz³a do drzewa BST
DrzewoBST::Wezel* DrzewoBST::dodajRekurencyjnie(Wezel* wezel, int wartosc) {
    /// Jeœli wêze³ jest pusty, twórz nowy wêze³
    if (!wezel) return new Wezel(wartosc);  
    /// Jeœli wartoœæ jest mniejsza, dodaj do lewego poddrzewa
    if (wartosc < wezel->wartosc) {  
        wezel->lewy = dodajRekurencyjnie(wezel->lewy, wartosc);
    }
    /// Jeœli wartoœæ jest wiêksza, dodaj do prawego poddrzewa
    else if (wartosc > wezel->wartosc) {  
        wezel->prawy = dodajRekurencyjnie(wezel->prawy, wartosc);
    }
    /// Zwróæ wêze³
    return wezel;  
}

/// Usuwa wêze³ o zadanej wartoœci z drzewa
bool DrzewoBST::usun(int wartosc) {
    /// Wywo³aj funkcjê usuwania rekurencyjnie
    korzen = usunRekurencyjnie(korzen, wartosc);  
    /// Zwróæ true, jeœli drzewo nie jest puste po usuniêciu
    return korzen != nullptr;  
}

/// Rekurencyjna pomocnicza funkcja do usuwania wêz³a w drzewie
DrzewoBST::Wezel* DrzewoBST::usunRekurencyjnie(Wezel* wezel, int wartosc) {
    /// Jeœli wêze³ jest pusty, zakoñcz
    if (!wezel) return nullptr;  
    /// Jeœli wartoœæ jest mniejsza, usuñ rekurencyjnie z lewego poddrzewa
    if (wartosc < wezel->wartosc) { 
        wezel->lewy = usunRekurencyjnie(wezel->lewy, wartosc);
    }
    /// Jeœli wartoœæ jest wiêksza, usuñ rekurencyjnie z prawego poddrzewa
    else if (wartosc > wezel->wartosc) {  
        wezel->prawy = usunRekurencyjnie(wezel->prawy, wartosc);
    }
    /// Jeœli znaleziono wêze³ do usuniêcia
    else {  
        /// Jeœli wêze³ nie ma lewego dziecka, zast¹p go prawym dzieckiem
        if (!wezel->lewy) {  
            Wezel* temp = wezel->prawy;
            delete wezel;
            return temp;
        }
        /// Jeœli wêze³ nie ma prawego dziecka, zast¹p go lewym dzieckiem
        else if (!wezel->prawy) {  
            Wezel* temp = wezel->lewy;
            delete wezel;
            return temp;
        }
        /// W przypadku wêz³a z dwoma dzieæmi, znajdŸ najmniejszy wêze³ w prawym poddrzewie
        Wezel* minWezel = znajdzMin(wezel->prawy);
        /// Zamieñ wartoœæ wêz³a z najmniejszym wêz³em
        wezel->wartosc = minWezel->wartosc;  
        /// Usuñ najmniejszy wêze³
        wezel->prawy = usunRekurencyjnie(wezel->prawy, minWezel->wartosc);  
    }
    /// Zwróæ nowy wêze³ po usuniêciu
    return wezel;  
}

/// Zwraca wêze³ o najmniejszej wartoœci w danym poddrzewie
DrzewoBST::Wezel* DrzewoBST::znajdzMin(Wezel* wezel) {
    /// PrzejdŸ do najdalej po³o¿onego lewego wêz³a
    while (wezel && wezel->lewy) wezel = wezel->lewy;  
    /// Zwróæ wêze³ o najmniejszej wartoœci
    return wezel;  
}

/// Szuka œcie¿ki do wêz³a o zadanej wartoœci w drzewie
std::vector<int> DrzewoBST::szukajSciezki(int wartosc) {
    std::vector<int> sciezka;
    if (szukajSciezkiRekurencyjnie(korzen, wartosc, sciezka)) {
        /// Jeœli œcie¿ka zosta³a znaleziona, zwróæ j¹
        return sciezka;  
    }
    else {
        /// Zwróæ pusty wektor, jeœli element nie zosta³ znaleziony
        return {};  
    }
}

/// Rekurencyjna funkcja do szukania œcie¿ki do wêz³a o zadanej wartoœci
bool DrzewoBST::szukajSciezkiRekurencyjnie(Wezel* wezel, int wartosc, std::vector<int>& sciezka) {
    /// Jeœli wêze³ jest pusty, zakoñcz
    if (!wezel) return false;  
    /// Dodaj wartoœæ wêz³a do œcie¿ki
    sciezka.push_back(wezel->wartosc);  
    if (wezel->wartosc == wartosc) {
        /// Jeœli znaleziono wêze³, zakoñcz
        return true;  
    }
    /// Rekurencyjnie sprawdzaj lewego lub prawego potomka w zale¿noœci od wartoœci
    if (wartosc < wezel->wartosc) {
        return szukajSciezkiRekurencyjnie(wezel->lewy, wartosc, sciezka);
    }
    else {
        return szukajSciezkiRekurencyjnie(wezel->prawy, wartosc, sciezka);
    }
}

/// Usuwa ca³e drzewo BST
void DrzewoBST::usunDrzewo() {
    /// Wywo³aj funkcjê usuwania rekurencyjnie dla korzenia
    usunDrzewo(korzen);  
    /// Ustaw korzeñ na nullptr po usuniêciu ca³ego drzewa
    korzen = nullptr; 
}

/// Rekurencyjna funkcja do usuwania ca³ego drzewa
void DrzewoBST::usunDrzewo(Wezel* wezel) {
    if (wezel) {
        /// Usuñ lewe poddrzewo
        usunDrzewo(wezel->lewy); 
        /// Usuñ prawe poddrzewo
        usunDrzewo(wezel->prawy);  
        /// Usuñ bie¿¹cy wêze³
        delete wezel; 
    }
}

/// Wypisuje wartoœci wêz³ów w drzewie w porz¹dku pre-order
void DrzewoBST::wyswietlPreOrder() {
    /// Wywo³aj funkcjê rekurencyjnie dla korzenia
    wyswietlPreOrder(korzen); 
    std::cout << std::endl;
}

/// Rekurencyjna funkcja do wypisywania w porz¹dku pre-order
void DrzewoBST::wyswietlPreOrder(Wezel* wezel) {
    if (wezel) {
        /// Wypisz wartoœæ bie¿¹cego wêz³a
        std::cout << wezel->wartosc << " ";  
        /// Wypisz lewe poddrzewo
        wyswietlPreOrder(wezel->lewy);  
        /// Wypisz prawe poddrzewo
        wyswietlPreOrder(wezel->prawy);  
    }
}

/// Wypisuje wartoœci wêz³ów w drzewie w porz¹dku in-order
void DrzewoBST::wyswietlInOrder() {
    /// Wywo³aj funkcjê rekurencyjnie dla korzenia
    wyswietlInOrder(korzen);  
    std::cout << std::endl;
}

/// Rekurencyjna funkcja do wypisywania w porz¹dku in-order
void DrzewoBST::wyswietlInOrder(Wezel* wezel) {
    if (wezel) {
        /// Wypisz lewe poddrzewo
        wyswietlInOrder(wezel->lewy);  
        /// Wypisz wartoœæ bie¿¹cego wêz³a
        std::cout << wezel->wartosc << " ";  
        /// Wypisz prawe poddrzewo
        wyswietlInOrder(wezel->prawy);  
    }
}

/// Wypisuje wartoœci wêz³ów w drzewie w porz¹dku post-order
void DrzewoBST::wyswietlPostOrder() {
    /// Wywo³aj funkcjê rekurencyjnie dla korzenia
    wyswietlPostOrder(korzen);  
    std::cout << std::endl;
}

/// Rekurencyjna funkcja do wypisywania w porz¹dku post-order
void DrzewoBST::wyswietlPostOrder(Wezel* wezel) {
    if (wezel) {
        /// Wypisz lewe poddrzewo
        wyswietlPostOrder(wezel->lewy);  
        /// Wypisz prawe poddrzewo
        wyswietlPostOrder(wezel->prawy);  
        /// Wypisz wartoœæ bie¿¹cego wêz³a
        std::cout << wezel->wartosc << " ";  
    }
}

/// Zapisuje drzewo do pliku tekstowego
void DrzewoBST::zapiszDoPliku(const std::string& nazwa_pliku) {
    /// Otwórz plik do zapisu
    std::ofstream plik(nazwa_pliku);  
    if (plik.is_open()) {
        /// Zapisz drzewo rekurencyjnie od korzenia
        zapiszDoPliku(korzen, plik);  
        plik.close();
    }
}

/// Rekurencyjna funkcja do zapisywania drzewa do pliku tekstowego
void DrzewoBST::zapiszDoPliku(Wezel* wezel, std::ofstream& plik) {
    if (wezel) {
        /// Zapisz wartoœæ wêz³a
        plik << wezel->wartosc << " ";  
        /// Zapisz lewe poddrzewo
        zapiszDoPliku(wezel->lewy, plik);
        /// Zapisz prawe poddrzewo
        zapiszDoPliku(wezel->prawy, plik);  
    }
}

/// Zapisuje drzewo do pliku binarnie
void DrzewoBST::zapiszDoPlikuBinarnie(const std::string& nazwa_pliku) {
    /// Otwórz plik do zapisu
    std::ofstream plik(nazwa_pliku, std::ios::binary);  
    if (plik.is_open()) {
        /// Zapisz drzewo binarnie
        zapiszDoPlikuBinarnie(korzen, plik); 
        plik.close();
    }
    else {
        std::cerr << "Nie mozna otworzyc pliku do zapisu binarnego.\n";
    }
}

/// Rekurencyjna funkcja do zapisywania drzewa do pliku binarnie
void DrzewoBST::zapiszDoPlikuBinarnie(Wezel* wezel, std::ofstream& plik) {
    if (wezel) {
        /// Zapisz wartoœæ wêz³a
        plik.write(reinterpret_cast<const char*>(&wezel->wartosc), sizeof(wezel->wartosc));  
        /// SprawdŸ, czy wêze³ ma lewe dziecko
        bool maLewy = (wezel->lewy != nullptr);  
        /// SprawdŸ, czy wêze³ ma prawe dziecko
        bool maPrawy = (wezel->prawy != nullptr);  
        /// Zapisz, czy ma lewe dziecko
        plik.write(reinterpret_cast<const char*>(&maLewy), sizeof(maLewy));  
        /// Zapisz, czy ma prawe dziecko
        plik.write(reinterpret_cast<const char*>(&maPrawy), sizeof(maPrawy));  
        /// Zapisz lewe poddrzewo
        if (wezel->lewy) zapiszDoPlikuBinarnie(wezel->lewy, plik);  
        /// Zapisz prawe poddrzewo
        if (wezel->prawy) zapiszDoPlikuBinarnie(wezel->prawy, plik);  
    }
}

/// Wczytuje drzewo z pliku zapisanego binarnie
void DrzewoBST::wczytajZPlikuBinarnie(const std::string& nazwa_pliku) {
    /// Otwórz plik zapisany binarnie do odczytu
    std::ifstream plik(nazwa_pliku, std::ios::binary);  
    if (plik.is_open()) {
        /// Usuñ istniej¹ce drzewo przed wczytaniem nowego
        usunDrzewo();  
        /// Wczytaj drzewo z pliku
        korzen = wczytajZPlikuBinarnie(plik); 
        plik.close();
    }
    else {
        std::cerr << "Nie mozna otworzyc pliku do odczytu binarnego.\n";
    }
}

/// Rekurencyjna funkcja do wczytywania drzewa z pliku zapisanego binarnie
DrzewoBST::Wezel* DrzewoBST::wczytajZPlikuBinarnie(std::ifstream& plik) {
    int wartosc;
    bool maLewy, maPrawy;
    if (!plik.read(reinterpret_cast<char*>(&wartosc), sizeof(wartosc))) {
        /// Zakoñcz, jeœli koniec pliku
        return nullptr; 
    }
    /// Utwórz nowy wêze³
    Wezel* wezel = new Wezel(wartosc);  
    /// Wczytaj, czy wêze³ ma lewe dziecko
    plik.read(reinterpret_cast<char*>(&maLewy), sizeof(maLewy));  
    /// Wczytaj, czy wêze³ ma prawe dziecko
    plik.read(reinterpret_cast<char*>(&maPrawy), sizeof(maPrawy)); 
    if (maLewy) {
        /// Wczytaj lewe poddrzewo
        wezel->lewy = wczytajZPlikuBinarnie(plik);  
    }
    if (maPrawy) {
        /// Wczytaj prawe poddrzewo
        wezel->prawy = wczytajZPlikuBinarnie(plik);  
    }
    /// Zwróæ wêze³
    return wezel;  
}