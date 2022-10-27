#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <random>
#include <numeric>    
#include "Studentas.h"
#include "Funkcijos.h"


int main()
{
    string a;
    vector<studentas> grupe;
    cout << "Jei norite duomenis ivesti pats, spauskite 'x', jei nuskaityti is failo 'y'\n";
    cin >> a;
    while (a != "x" && a!= "y") {
        cout << "Klaida, iveskite x arba y ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> a;
    }
    if (a == "x") {
        grupe = ivedimas();
        print_student(grupe, 0);
    }
    else {
        int pazymiu_sk;
        char temp;
        std::vector<studentas> Eil;
        read_from_file(Eil, &pazymiu_sk);
        print_student(Eil, pazymiu_sk);
        system("pause");
        return 0;
    }

}

