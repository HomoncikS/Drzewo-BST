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