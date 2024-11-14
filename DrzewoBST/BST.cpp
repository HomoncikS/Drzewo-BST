#include "BST.h"

/// Dodaje nowy w�ze� o zadanej warto�ci do drzewa BST
void DrzewoBST::dodaj(int wartosc) {
    korzen = dodajRekurencyjnie(korzen, wartosc);  // Rozpoczyna dodawanie rekurencyjnie od korzenia
}

/// Rekurencyjna pomocnicza funkcja do dodawania nowego w�z�a do drzewa BST
DrzewoBST::Wezel* DrzewoBST::dodajRekurencyjnie(Wezel* wezel, int wartosc) {
    /// Je�li w�ze� jest pusty, tw�rz nowy w�ze�
    if (!wezel) return new Wezel(wartosc);  
    /// Je�li warto�� jest mniejsza, dodaj do lewego poddrzewa
    if (wartosc < wezel->wartosc) {  
        wezel->lewy = dodajRekurencyjnie(wezel->lewy, wartosc);
    }
    /// Je�li warto�� jest wi�ksza, dodaj do prawego poddrzewa
    else if (wartosc > wezel->wartosc) {  
        wezel->prawy = dodajRekurencyjnie(wezel->prawy, wartosc);
    }
    /// Zwr�� w�ze�
    return wezel;  
}

/// Usuwa w�ze� o zadanej warto�ci z drzewa
bool DrzewoBST::usun(int wartosc) {
    /// Wywo�aj funkcj� usuwania rekurencyjnie
    korzen = usunRekurencyjnie(korzen, wartosc);  
    /// Zwr�� true, je�li drzewo nie jest puste po usuni�ciu
    return korzen != nullptr;  
}

/// Rekurencyjna pomocnicza funkcja do usuwania w�z�a w drzewie
DrzewoBST::Wezel* DrzewoBST::usunRekurencyjnie(Wezel* wezel, int wartosc) {
    /// Je�li w�ze� jest pusty, zako�cz
    if (!wezel) return nullptr;  
    /// Je�li warto�� jest mniejsza, usu� rekurencyjnie z lewego poddrzewa
    if (wartosc < wezel->wartosc) { 
        wezel->lewy = usunRekurencyjnie(wezel->lewy, wartosc);
    }
    /// Je�li warto�� jest wi�ksza, usu� rekurencyjnie z prawego poddrzewa
    else if (wartosc > wezel->wartosc) {  
        wezel->prawy = usunRekurencyjnie(wezel->prawy, wartosc);
    }
    /// Je�li znaleziono w�ze� do usuni�cia
    else {  
        /// Je�li w�ze� nie ma lewego dziecka, zast�p go prawym dzieckiem
        if (!wezel->lewy) {  
            Wezel* temp = wezel->prawy;
            delete wezel;
            return temp;
        }
        /// Je�li w�ze� nie ma prawego dziecka, zast�p go lewym dzieckiem
        else if (!wezel->prawy) {  
            Wezel* temp = wezel->lewy;
            delete wezel;
            return temp;
        }
        /// W przypadku w�z�a z dwoma dzie�mi, znajd� najmniejszy w�ze� w prawym poddrzewie
        Wezel* minWezel = znajdzMin(wezel->prawy);
        /// Zamie� warto�� w�z�a z najmniejszym w�z�em
        wezel->wartosc = minWezel->wartosc;  
        /// Usu� najmniejszy w�ze�
        wezel->prawy = usunRekurencyjnie(wezel->prawy, minWezel->wartosc);  
    }
    /// Zwr�� nowy w�ze� po usuni�ciu
    return wezel;  
}

/// Zwraca w�ze� o najmniejszej warto�ci w danym poddrzewie
DrzewoBST::Wezel* DrzewoBST::znajdzMin(Wezel* wezel) {
    /// Przejd� do najdalej po�o�onego lewego w�z�a
    while (wezel && wezel->lewy) wezel = wezel->lewy;  
    /// Zwr�� w�ze� o najmniejszej warto�ci
    return wezel;  
}

/// Szuka �cie�ki do w�z�a o zadanej warto�ci w drzewie
std::vector<int> DrzewoBST::szukajSciezki(int wartosc) {
    std::vector<int> sciezka;
    if (szukajSciezkiRekurencyjnie(korzen, wartosc, sciezka)) {
        /// Je�li �cie�ka zosta�a znaleziona, zwr�� j�
        return sciezka;  
    }
    else {
        /// Zwr�� pusty wektor, je�li element nie zosta� znaleziony
        return {};  
    }
}

/// Rekurencyjna funkcja do szukania �cie�ki do w�z�a o zadanej warto�ci
bool DrzewoBST::szukajSciezkiRekurencyjnie(Wezel* wezel, int wartosc, std::vector<int>& sciezka) {
    /// Je�li w�ze� jest pusty, zako�cz
    if (!wezel) return false;  
    /// Dodaj warto�� w�z�a do �cie�ki
    sciezka.push_back(wezel->wartosc);  
    if (wezel->wartosc == wartosc) {
        /// Je�li znaleziono w�ze�, zako�cz
        return true;  
    }
    /// Rekurencyjnie sprawdzaj lewego lub prawego potomka w zale�no�ci od warto�ci
    if (wartosc < wezel->wartosc) {
        return szukajSciezkiRekurencyjnie(wezel->lewy, wartosc, sciezka);
    }
    else {
        return szukajSciezkiRekurencyjnie(wezel->prawy, wartosc, sciezka);
    }
}

/// Usuwa ca�e drzewo BST
void DrzewoBST::usunDrzewo() {
    /// Wywo�aj funkcj� usuwania rekurencyjnie dla korzenia
    usunDrzewo(korzen);  
    /// Ustaw korze� na nullptr po usuni�ciu ca�ego drzewa
    korzen = nullptr; 
}

/// Rekurencyjna funkcja do usuwania ca�ego drzewa
void DrzewoBST::usunDrzewo(Wezel* wezel) {
    if (wezel) {
        /// Usu� lewe poddrzewo
        usunDrzewo(wezel->lewy); 
        /// Usu� prawe poddrzewo
        usunDrzewo(wezel->prawy);  
        /// Usu� bie��cy w�ze�
        delete wezel; 
    }
}

/// Wypisuje warto�ci w�z��w w drzewie w porz�dku pre-order
void DrzewoBST::wyswietlPreOrder() {
    /// Wywo�aj funkcj� rekurencyjnie dla korzenia
    wyswietlPreOrder(korzen); 
    std::cout << std::endl;
}

/// Rekurencyjna funkcja do wypisywania w porz�dku pre-order
void DrzewoBST::wyswietlPreOrder(Wezel* wezel) {
    if (wezel) {
        /// Wypisz warto�� bie��cego w�z�a
        std::cout << wezel->wartosc << " ";  
        /// Wypisz lewe poddrzewo
        wyswietlPreOrder(wezel->lewy);  
        /// Wypisz prawe poddrzewo
        wyswietlPreOrder(wezel->prawy);  
    }
}

/// Wypisuje warto�ci w�z��w w drzewie w porz�dku in-order
void DrzewoBST::wyswietlInOrder() {
    /// Wywo�aj funkcj� rekurencyjnie dla korzenia
    wyswietlInOrder(korzen);  
    std::cout << std::endl;
}

/// Rekurencyjna funkcja do wypisywania w porz�dku in-order
void DrzewoBST::wyswietlInOrder(Wezel* wezel) {
    if (wezel) {
        /// Wypisz lewe poddrzewo
        wyswietlInOrder(wezel->lewy);  
        /// Wypisz warto�� bie��cego w�z�a
        std::cout << wezel->wartosc << " ";  
        /// Wypisz prawe poddrzewo
        wyswietlInOrder(wezel->prawy);  
    }
}

/// Wypisuje warto�ci w�z��w w drzewie w porz�dku post-order
void DrzewoBST::wyswietlPostOrder() {
    /// Wywo�aj funkcj� rekurencyjnie dla korzenia
    wyswietlPostOrder(korzen);  
    std::cout << std::endl;
}

/// Rekurencyjna funkcja do wypisywania w porz�dku post-order
void DrzewoBST::wyswietlPostOrder(Wezel* wezel) {
    if (wezel) {
        /// Wypisz lewe poddrzewo
        wyswietlPostOrder(wezel->lewy);  
        /// Wypisz prawe poddrzewo
        wyswietlPostOrder(wezel->prawy);  
        /// Wypisz warto�� bie��cego w�z�a
        std::cout << wezel->wartosc << " ";  
    }
}

/// Zapisuje drzewo do pliku tekstowego
void DrzewoBST::zapiszDoPliku(const std::string& nazwa_pliku) {
    /// Otw�rz plik do zapisu
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
        /// Zapisz warto�� w�z�a
        plik << wezel->wartosc << " ";  
        /// Zapisz lewe poddrzewo
        zapiszDoPliku(wezel->lewy, plik);
        /// Zapisz prawe poddrzewo
        zapiszDoPliku(wezel->prawy, plik);  
    }
}

/// Zapisuje drzewo do pliku binarnie
void DrzewoBST::zapiszDoPlikuBinarnie(const std::string& nazwa_pliku) {
    /// Otw�rz plik do zapisu
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
        /// Zapisz warto�� w�z�a
        plik.write(reinterpret_cast<const char*>(&wezel->wartosc), sizeof(wezel->wartosc));  
        /// Sprawd�, czy w�ze� ma lewe dziecko
        bool maLewy = (wezel->lewy != nullptr);  
        /// Sprawd�, czy w�ze� ma prawe dziecko
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
    /// Otw�rz plik zapisany binarnie do odczytu
    std::ifstream plik(nazwa_pliku, std::ios::binary);  
    if (plik.is_open()) {
        /// Usu� istniej�ce drzewo przed wczytaniem nowego
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
        /// Zako�cz, je�li koniec pliku
        return nullptr; 
    }
    /// Utw�rz nowy w�ze�
    Wezel* wezel = new Wezel(wartosc);  
    /// Wczytaj, czy w�ze� ma lewe dziecko
    plik.read(reinterpret_cast<char*>(&maLewy), sizeof(maLewy));  
    /// Wczytaj, czy w�ze� ma prawe dziecko
    plik.read(reinterpret_cast<char*>(&maPrawy), sizeof(maPrawy)); 
    if (maLewy) {
        /// Wczytaj lewe poddrzewo
        wezel->lewy = wczytajZPlikuBinarnie(plik);  
    }
    if (maPrawy) {
        /// Wczytaj prawe poddrzewo
        wezel->prawy = wczytajZPlikuBinarnie(plik);  
    }
    /// Zwr�� w�ze�
    return wezel;  
}