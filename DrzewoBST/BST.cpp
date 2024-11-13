#include "BST.h"

void DrzewoBST::dodaj(int wartosc) {
    korzen = dodajRekurencyjnie(korzen, wartosc);
}

DrzewoBST::Wezel* DrzewoBST::dodajRekurencyjnie(Wezel* wezel, int wartosc) {
    if (!wezel) return new Wezel(wartosc);
    if (wartosc < wezel->wartosc) {
        wezel->lewy = dodajRekurencyjnie(wezel->lewy, wartosc);
    }
    else if (wartosc > wezel->wartosc) {
        wezel->prawy = dodajRekurencyjnie(wezel->prawy, wartosc);
    }
    return wezel;
}

bool DrzewoBST::usun(int wartosc) {
    korzen = usunRekurencyjnie(korzen, wartosc);
    return korzen != nullptr;
}

DrzewoBST::Wezel* DrzewoBST::usunRekurencyjnie(Wezel* wezel, int wartosc) {
    if (!wezel) return nullptr;
    if (wartosc < wezel->wartosc) {
        wezel->lewy = usunRekurencyjnie(wezel->lewy, wartosc);
    }
    else if (wartosc > wezel->wartosc) {
        wezel->prawy = usunRekurencyjnie(wezel->prawy, wartosc);
    }
    else {
        if (!wezel->lewy) {
            Wezel* temp = wezel->prawy;
            delete wezel;
            return temp;
        }
        else if (!wezel->prawy) {
            Wezel* temp = wezel->lewy;
            delete wezel;
            return temp;
        }
        Wezel* minWezel = znajdzMin(wezel->prawy);
        wezel->wartosc = minWezel->wartosc;
        wezel->prawy = usunRekurencyjnie(wezel->prawy, minWezel->wartosc);
    }
    return wezel;
}

DrzewoBST::Wezel* DrzewoBST::znajdzMin(Wezel* wezel) {
    while (wezel && wezel->lewy) wezel = wezel->lewy;
    return wezel;
}

std::vector<int> DrzewoBST::szukajSciezki(int wartosc) {
    std::vector<int> sciezka;
    if (szukajSciezkiRekurencyjnie(korzen, wartosc, sciezka)) {
        return sciezka;
    }
    else {
        return {}; // Zwróæ pusty wektor, jeœli element nie zosta³ znaleziony
    }
}

bool DrzewoBST::szukajSciezkiRekurencyjnie(Wezel* wezel, int wartosc, std::vector<int>& sciezka) {
    if (!wezel) return false;
    sciezka.push_back(wezel->wartosc);
    if (wezel->wartosc == wartosc) {
        return true;
    }
    if (wartosc < wezel->wartosc) {
        return szukajSciezkiRekurencyjnie(wezel->lewy, wartosc, sciezka);
    }
    else {
        return szukajSciezkiRekurencyjnie(wezel->prawy, wartosc, sciezka);
    }
}

void DrzewoBST::usunDrzewo() {
    usunDrzewo(korzen);
    korzen = nullptr;
}

void DrzewoBST::usunDrzewo(Wezel* wezel) {
    if (wezel) {
        usunDrzewo(wezel->lewy);
        usunDrzewo(wezel->prawy);
        delete wezel;
    }
}

void DrzewoBST::wyswietlPreOrder() {
    wyswietlPreOrder(korzen);
    std::cout << std::endl;
}

void DrzewoBST::wyswietlPreOrder(Wezel* wezel) {
    if (wezel) {
        std::cout << wezel->wartosc << " ";
        wyswietlPreOrder(wezel->lewy);
        wyswietlPreOrder(wezel->prawy);
    }
}

void DrzewoBST::wyswietlInOrder() {
    wyswietlInOrder(korzen);
    std::cout << std::endl;
}

void DrzewoBST::wyswietlInOrder(Wezel* wezel) {
    if (wezel) {
        wyswietlInOrder(wezel->lewy);
        std::cout << wezel->wartosc << " ";
        wyswietlInOrder(wezel->prawy);
    }
}

void DrzewoBST::wyswietlPostOrder() {
    wyswietlPostOrder(korzen);
    std::cout << std::endl;
}

void DrzewoBST::wyswietlPostOrder(Wezel* wezel) {
    if (wezel) {
        wyswietlPostOrder(wezel->lewy);
        wyswietlPostOrder(wezel->prawy);
        std::cout << wezel->wartosc << " ";
    }
}

void DrzewoBST::zapiszDoPliku(const std::string& nazwa_pliku) {
    std::ofstream plik(nazwa_pliku);
    if (plik.is_open()) {
        zapiszDoPliku(korzen, plik);
        plik.close();
    }
}

void DrzewoBST::zapiszDoPliku(Wezel* wezel, std::ofstream& plik) {
    if (wezel) {
        plik << wezel->wartosc << " ";
        zapiszDoPliku(wezel->lewy, plik);
        zapiszDoPliku(wezel->prawy, plik);
    }
}

void DrzewoBST::zapiszDoPlikuBinarnego(const std::string& nazwa_pliku) {
    std::ofstream plik(nazwa_pliku, std::ios::binary);
    if (plik.is_open()) {
        zapiszDoPlikuBinarnego(korzen, plik);
        plik.close();
    }
    else {
        std::cerr << "Nie mozna otworzyc pliku do zapisu binarnego.\n";
    }
}

void DrzewoBST::zapiszDoPlikuBinarnego(Wezel* wezel, std::ofstream& plik) {
    if (wezel) {
        plik.write(reinterpret_cast<const char*>(&wezel->wartosc), sizeof(wezel->wartosc));
        bool maLewy = (wezel->lewy != nullptr);
        bool maPrawy = (wezel->prawy != nullptr);
        plik.write(reinterpret_cast<const char*>(&maLewy), sizeof(maLewy));
        plik.write(reinterpret_cast<const char*>(&maPrawy), sizeof(maPrawy));
        if (wezel->lewy) zapiszDoPlikuBinarnego(wezel->lewy, plik);
        if (wezel->prawy) zapiszDoPlikuBinarnego(wezel->prawy, plik);
    }
}

void DrzewoBST::wczytajZPlikuBinarnego(const std::string& nazwa_pliku) {
    std::ifstream plik(nazwa_pliku, std::ios::binary);
    if (plik.is_open()) {
        usunDrzewo();
        korzen = wczytajZPlikuBinarnego(plik);
        plik.close();
    }
    else {
        std::cerr << "Nie mozna otworzyc pliku do odczytu binarnego.\n";
    }
}

DrzewoBST::Wezel* DrzewoBST::wczytajZPlikuBinarnego(std::ifstream& plik) {
    int wartosc;
    bool maLewy, maPrawy;
    if (!plik.read(reinterpret_cast<char*>(&wartosc), sizeof(wartosc))) {
        return nullptr;
    }
    Wezel* wezel = new Wezel(wartosc);
    plik.read(reinterpret_cast<char*>(&maLewy), sizeof(maLewy));
    plik.read(reinterpret_cast<char*>(&maPrawy), sizeof(maPrawy));
    if (maLewy) {
        wezel->lewy = wczytajZPlikuBinarnego(plik);
    }
    if (maPrawy) {
        wezel->prawy = wczytajZPlikuBinarnego(plik);
    }
    return wezel;
}