#include "BST.h"

// Dodaje nowy w�ze� o zadanej warto�ci do drzewa BST
void DrzewoBST::dodaj(int wartosc) {
    korzen = dodajRekurencyjnie(korzen, wartosc);  // Rozpoczyna dodawanie rekurencyjnie od korzenia
}

// Rekurencyjna pomocnicza funkcja do dodawania nowego w�z�a do drzewa BST
DrzewoBST::Wezel* DrzewoBST::dodajRekurencyjnie(Wezel* wezel, int wartosc) {
    if (!wezel) return new Wezel(wartosc);  // Je�li w�ze� jest pusty, tw�rz nowy w�ze�
    if (wartosc < wezel->wartosc) {  // Je�li warto�� jest mniejsza, dodaj do lewego poddrzewa
        wezel->lewy = dodajRekurencyjnie(wezel->lewy, wartosc);
    }
    else if (wartosc > wezel->wartosc) {  // Je�li warto�� jest wi�ksza, dodaj do prawego poddrzewa
        wezel->prawy = dodajRekurencyjnie(wezel->prawy, wartosc);
    }
    return wezel;  // Zwr�� w�ze�
}

// Usuwa w�ze� o zadanej warto�ci z drzewa
bool DrzewoBST::usun(int wartosc) {
    korzen = usunRekurencyjnie(korzen, wartosc);  // Wywo�aj funkcj� usuwania rekurencyjnie
    return korzen != nullptr;  // Zwr�� true, je�li drzewo nie jest puste po usuni�ciu
}

// Rekurencyjna pomocnicza funkcja do usuwania w�z�a w drzewie
DrzewoBST::Wezel* DrzewoBST::usunRekurencyjnie(Wezel* wezel, int wartosc) {
    if (!wezel) return nullptr;  // Je�li w�ze� jest pusty, zako�cz
    if (wartosc < wezel->wartosc) {  // Je�li warto�� jest mniejsza, usu� rekurencyjnie z lewego poddrzewa
        wezel->lewy = usunRekurencyjnie(wezel->lewy, wartosc);
    }
    else if (wartosc > wezel->wartosc) {  // Je�li warto�� jest wi�ksza, usu� rekurencyjnie z prawego poddrzewa
        wezel->prawy = usunRekurencyjnie(wezel->prawy, wartosc);
    }
    else {  // Je�li znaleziono w�ze� do usuni�cia
        if (!wezel->lewy) {  // Je�li w�ze� nie ma lewego dziecka, zast�p go prawym dzieckiem
            Wezel* temp = wezel->prawy;
            delete wezel;
            return temp;
        }
        else if (!wezel->prawy) {  // Je�li w�ze� nie ma prawego dziecka, zast�p go lewym dzieckiem
            Wezel* temp = wezel->lewy;
            delete wezel;
            return temp;
        }
        // W przypadku w�z�a z dwoma dzie�mi, znajd� najmniejszy w�ze� w prawym poddrzewie
        Wezel* minWezel = znajdzMin(wezel->prawy);
        wezel->wartosc = minWezel->wartosc;  // Zamie� warto�� w�z�a z najmniejszym w�z�em
        wezel->prawy = usunRekurencyjnie(wezel->prawy, minWezel->wartosc);  // Usu� najmniejszy w�ze�
    }
    return wezel;  // Zwr�� nowy w�ze� po usuni�ciu
}

// Zwraca w�ze� o najmniejszej warto�ci w danym poddrzewie
DrzewoBST::Wezel* DrzewoBST::znajdzMin(Wezel* wezel) {
    while (wezel && wezel->lewy) wezel = wezel->lewy;  // Przejd� do najdalej po�o�onego lewego w�z�a
    return wezel;  // Zwr�� w�ze� o najmniejszej warto�ci
}

// Szuka �cie�ki do w�z�a o zadanej warto�ci w drzewie
std::vector<int> DrzewoBST::szukajSciezki(int wartosc) {
    std::vector<int> sciezka;
    if (szukajSciezkiRekurencyjnie(korzen, wartosc, sciezka)) {
        return sciezka;  // Je�li �cie�ka zosta�a znaleziona, zwr�� j�
    }
    else {
        return {};  // Zwr�� pusty wektor, je�li element nie zosta� znaleziony
    }
}

// Rekurencyjna funkcja do szukania �cie�ki do w�z�a o zadanej warto�ci
bool DrzewoBST::szukajSciezkiRekurencyjnie(Wezel* wezel, int wartosc, std::vector<int>& sciezka) {
    if (!wezel) return false;  // Je�li w�ze� jest pusty, zako�cz
    sciezka.push_back(wezel->wartosc);  // Dodaj warto�� w�z�a do �cie�ki
    if (wezel->wartosc == wartosc) {
        return true;  // Je�li znaleziono w�ze�, zako�cz
    }
    // Rekurencyjnie sprawdzaj lewego lub prawego potomka w zale�no�ci od warto�ci
    if (wartosc < wezel->wartosc) {
        return szukajSciezkiRekurencyjnie(wezel->lewy, wartosc, sciezka);
    }
    else {
        return szukajSciezkiRekurencyjnie(wezel->prawy, wartosc, sciezka);
    }
}

// Usuwa ca�e drzewo BST
void DrzewoBST::usunDrzewo() {
    usunDrzewo(korzen);  // Wywo�aj funkcj� usuwania rekurencyjnie dla korzenia
    korzen = nullptr;  // Ustaw korze� na nullptr po usuni�ciu ca�ego drzewa
}

// Rekurencyjna funkcja do usuwania ca�ego drzewa
void DrzewoBST::usunDrzewo(Wezel* wezel) {
    if (wezel) {
        usunDrzewo(wezel->lewy);  // Usu� lewe poddrzewo
        usunDrzewo(wezel->prawy);  // Usu� prawe poddrzewo
        delete wezel;  // Usu� bie��cy w�ze�
    }
}

// Wypisuje warto�ci w�z��w w drzewie w porz�dku pre-order
void DrzewoBST::wyswietlPreOrder() {
    wyswietlPreOrder(korzen);  // Wywo�aj funkcj� rekurencyjnie dla korzenia
    std::cout << std::endl;
}

// Rekurencyjna funkcja do wypisywania w porz�dku pre-order
void DrzewoBST::wyswietlPreOrder(Wezel* wezel) {
    if (wezel) {
        std::cout << wezel->wartosc << " ";  // Wypisz warto�� bie��cego w�z�a
        wyswietlPreOrder(wezel->lewy);  // Wypisz lewe poddrzewo
        wyswietlPreOrder(wezel->prawy);  // Wypisz prawe poddrzewo
    }
}

// Wypisuje warto�ci w�z��w w drzewie w porz�dku in-order
void DrzewoBST::wyswietlInOrder() {
    wyswietlInOrder(korzen);  // Wywo�aj funkcj� rekurencyjnie dla korzenia
    std::cout << std::endl;
}

// Rekurencyjna funkcja do wypisywania w porz�dku in-order
void DrzewoBST::wyswietlInOrder(Wezel* wezel) {
    if (wezel) {
        wyswietlInOrder(wezel->lewy);  // Wypisz lewe poddrzewo
        std::cout << wezel->wartosc << " ";  // Wypisz warto�� bie��cego w�z�a
        wyswietlInOrder(wezel->prawy);  // Wypisz prawe poddrzewo
    }
}

// Wypisuje warto�ci w�z��w w drzewie w porz�dku post-order
void DrzewoBST::wyswietlPostOrder() {
    wyswietlPostOrder(korzen);  // Wywo�aj funkcj� rekurencyjnie dla korzenia
    std::cout << std::endl;
}

// Rekurencyjna funkcja do wypisywania w porz�dku post-order
void DrzewoBST::wyswietlPostOrder(Wezel* wezel) {
    if (wezel) {
        wyswietlPostOrder(wezel->lewy);  // Wypisz lewe poddrzewo
        wyswietlPostOrder(wezel->prawy);  // Wypisz prawe poddrzewo
        std::cout << wezel->wartosc << " ";  // Wypisz warto�� bie��cego w�z�a
    }
}

// Zapisuje drzewo do pliku tekstowego
void DrzewoBST::zapiszDoPliku(const std::string& nazwa_pliku) {
    std::ofstream plik(nazwa_pliku);  // Otw�rz plik do zapisu
    if (plik.is_open()) {
        zapiszDoPliku(korzen, plik);  // Zapisz drzewo rekurencyjnie od korzenia
        plik.close();
    }
}

// Rekurencyjna funkcja do zapisywania drzewa do pliku tekstowego
void DrzewoBST::zapiszDoPliku(Wezel* wezel, std::ofstream& plik) {
    if (wezel) {
        plik << wezel->wartosc << " ";  // Zapisz warto�� w�z�a
        zapiszDoPliku(wezel->lewy, plik);  // Zapisz lewe poddrzewo
        zapiszDoPliku(wezel->prawy, plik);  // Zapisz prawe poddrzewo
    }
}

// Zapisuje drzewo do pliku binarnie
void DrzewoBST::zapiszDoPlikuBinarnie(const std::string& nazwa_pliku) {
    std::ofstream plik(nazwa_pliku, std::ios::binary);  // Otw�rz plik do zapisu
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
        plik.write(reinterpret_cast<const char*>(&wezel->wartosc), sizeof(wezel->wartosc));  // Zapisz warto�� w�z�a
        bool maLewy = (wezel->lewy != nullptr);  // Sprawd�, czy w�ze� ma lewe dziecko
        bool maPrawy = (wezel->prawy != nullptr);  // Sprawd�, czy w�ze� ma prawe dziecko
        plik.write(reinterpret_cast<const char*>(&maLewy), sizeof(maLewy));  // Zapisz, czy ma lewe dziecko
        plik.write(reinterpret_cast<const char*>(&maPrawy), sizeof(maPrawy));  // Zapisz, czy ma prawe dziecko
        if (wezel->lewy) zapiszDoPlikuBinarnie(wezel->lewy, plik);  // Zapisz lewe poddrzewo
        if (wezel->prawy) zapiszDoPlikuBinarnie(wezel->prawy, plik);  // Zapisz prawe poddrzewo
    }
}

// Wczytuje drzewo z pliku zapisanego binarnie
void DrzewoBST::wczytajZPlikuBinarnie(const std::string& nazwa_pliku) {
    std::ifstream plik(nazwa_pliku, std::ios::binary);  // Otw�rz plik zapisany binarnie do odczytu
    if (plik.is_open()) {
        usunDrzewo();  // Usu� istniej�ce drzewo przed wczytaniem nowego
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
        return nullptr;  // Zako�cz, je�li koniec pliku
    }
    Wezel* wezel = new Wezel(wartosc);  // Utw�rz nowy w�ze�
    plik.read(reinterpret_cast<char*>(&maLewy), sizeof(maLewy));  // Wczytaj, czy w�ze� ma lewe dziecko
    plik.read(reinterpret_cast<char*>(&maPrawy), sizeof(maPrawy));  // Wczytaj, czy w�ze� ma prawe dziecko
    if (maLewy) {
        wezel->lewy = wczytajZPlikuBinarnie(plik);  // Wczytaj lewe poddrzewo
    }
    if (maPrawy) {
        wezel->prawy = wczytajZPlikuBinarnie(plik);  // Wczytaj prawe poddrzewo
    }
    return wezel;  // Zwr�� w�ze�
}