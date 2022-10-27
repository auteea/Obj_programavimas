
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

using namespace std;

float count_median(std::vector<int> pazymiai) 
{
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        if (pazymiai[i] != 0)
        {
            counter++;
        }
        if (pazymiai[i] == -1)
        {
            pazymiai[i] = 0;
            counter--;
            break;
        }
    }
    if (counter % 2 == 0)
    {
        return float(((pazymiai[counter / 2 - 1]) + (pazymiai[(counter / 2)])) / 2.0);
    }
    else
    {
        return float(pazymiai[(counter / 2)]);
    }
}

void print_student(std::vector<studentas> Eil, int pazymiu_sk) {
    std::ofstream output;
    output.open("rezultatai.txt");
    output << std::setw(20) << std::left << "Vardas"
        << std::setw(20) << std::left << "Pavarde"
        << std::setw(18) << std::left << "Galutinis(vid.)/"
        << std::left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < Eil.size(); i++)
    {
        if (Eil[i].ivestis == "") {
            output << std::setw(20) << std::left << Eil[i].Vard
                << std::setw(20) << std::left << Eil[i].Pav
                << std::setw(18) << std::left << Eil[i].GP
                << count_median(Eil[i].paz) << std::endl;
        }
        else if (Eil[i].ivestis == "0") {
            output << std::setw(20) << std::left << Eil[i].Vard
                << std::setw(20) << std::left << Eil[i].Pav
                << std::setw(18) << std::left << "----"
                << Eil[i].med << std::endl;
        }
        else {
            output << std::setw(20) << std::left << Eil[i].Vard
                << std::setw(20) << std::left << Eil[i].Pav
                << std::setw(18) << std::left << Eil[i].GP
                << "---" << std::endl;
        }
    }
    output << "\n\n";
}

unsigned int countWordsInString(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

void read_from_file(std::vector<studentas>& Eil, int* pazymiu_sk)
{
    int student_counter = 0;
    int temp;
    std::ifstream fileRead;
    std::string buff;
    fileRead.open("studentai100000.txt.txt");
    if (fileRead.is_open())
    {
        getline(fileRead >> std::ws, buff);
        *pazymiu_sk = countWordsInString(buff) - 3;
        while (true)
        {

            Eil.resize(Eil.size() + 1);
            fileRead >> Eil.at(student_counter).Vard;
            if (fileRead.eof()) { Eil.pop_back(); break; }
            fileRead >> Eil.at(student_counter).Pav;
            for (int i = 0; i < *pazymiu_sk; i++)
            {
                fileRead >> temp;
                Eil.at(student_counter).paz.push_back(temp);
            }
            fileRead >> Eil.at(student_counter).egz;
            //std::cout << Eil.at(student_counter).Vard;
            Eil.at(student_counter).GP = Eil.at(student_counter).GP / *pazymiu_sk;
            Eil.at(student_counter).GP = Eil.at(student_counter).GP * 0.4 + 0.6 * Eil.at(student_counter).egz;
            student_counter++;
        }
    
    }
    else { std::cout << "-\n"; }
}
vector<studentas> ivedimas() {
    vector<studentas> grupe;
    studentas stud;
    cout << "Iveskite studentu skaiciu: ";
    int n;
    cin >> n;
    while (cin.fail()) {
        cout << "Klaida, iveskite skaiciu  ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> n;
    }
    grupe.reserve(n);
    for (int i = 0; i < n; i++) {
        stud.paz.reserve(20);
        cout << "Iveskite " << i + 1 << "-aji varda: ";
        cin >> stud.Vard;
        cout << "pavarde: ";
        cin >> stud.Pav;
        string generuoja;
        cout << "Jei norite ivesti pazymius pats spauskite 0 , jei nenorite spauskite bet kuri kita mygtuka  ";
        cin >> generuoja;
        if (generuoja != "0") {
            cout << "egzamino pazimys: ";
            stud.egz = 1 + rand() % 10;
            cout << stud.egz << "\n";
            string x = "x";
            cout << i + 1 << "-ojo studento nd pazymiai, kai noresite sustoti, irasykite 0: \n";
            int b = 1 + rand() % 10;
            for (int j = 0; j < b; j++) {
                int a = 1 + rand() % 10;
                cout << a << "\n";
                stud.paz.push_back(a);
            }
        }
        else {
            cout << "egzamino pazimys: ";
            int egzaminas;
            cin >> egzaminas;
            while (cin.fail() || egzaminas < 1 || egzaminas>10) {
                cout << "klaida, iveskite skaiciu ne didesni uz 10  ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> egzaminas;
            }
            stud.egz = egzaminas;
            cout << i + 1 << "-ojo studento nd pazymiai, kai noresite sustoti, irasykite 0: \n";
            int x = 1;
            cin >> x;
            while (cin.fail() || x < 0 || x>10) {
                cout << "klaida, iveskite teigiama skaiciu, mazesni uz 10 (arba 0) ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> x;
            }
            while (x != 0) {
                stud.paz.push_back(x);
                cin >> x;
                while (cin.fail() || x < 0 || x>10) {
                    cout << "klaida, iveskite teigiama skaiciu, mazesni uz 10 (arba 0) ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> x;
                }
            }
        }

        sort(stud.paz.begin(), stud.paz.end());
        int c;
        c = stud.paz.size();
        float mediana;
        if (c != 0) {
            if (c % 2 != 0)	mediana = stud.paz[c / 2 + 0.5];
            else    			mediana = ((float)stud.paz[c / 2 - 1] + (float)stud.paz[c / 2]) / 2;
        }
        stud.med = mediana * 0.4 + 0.6 * stud.egz;
        if (c == 0) stud.GP = 0.6 * stud.egz;
        else {
            float suma = 0;
            suma = accumulate(stud.paz.begin(), stud.paz.end(), 0);
            float vid = suma / c;
            stud.GP = vid * 0.4 + 0.6 * stud.egz;
        }
        cout << "\n Jei noresite gauti galutini pazymi pagal mediana spauskite: 0 \n jei pagal vidurki: bet ka kita \n";
        string ivestis;
        cin >> ivestis;
        stud.ivestis = ivestis;

        grupe.push_back(stud);
        stud.paz.clear();
    }
    return grupe;
}
