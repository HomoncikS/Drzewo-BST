#ifndef ZAPISODCZYT_H
#define ZAPISODCZYT_H

#include <string>
#include "BST.h"

class ZapisOdczyt {
public:
    static void zapiszDrzewoBinarne(DrzewoBST& drzewo, const std::string& nazwa_pliku);
    static void wczytajDrzewoBinarne(DrzewoBST& drzewo, const std::string& nazwa_pliku);
};

#endif