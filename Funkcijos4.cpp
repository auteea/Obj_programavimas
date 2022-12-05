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
#include <chrono>
#include <list>

#include "Funkcijos4.h"
#include "Studentas4.h"


using namespace std;

studentas get(list<studentas> _list, int _i) {
    list<studentas>::iterator it = _list.begin();
    for (int i = 0; i < _i; i++) {
        ++it;
    }
    return *it;
}

void print_student(list<studentas> mokinys, int pazymiu_sk, string filename) {

    ofstream output;
    output.open(filename);
    output << std::setw(20) << std::left << "Vardas"
        << std::setw(20) << std::left << "Pavarde"
        << std::setw(18) << std::left << "Galutinis\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < mokinys.size(); i++)
    {

        studentas studentas = get(mokinys, i);
        if (studentas.ivestis == "0") {
            output << studentas.Vard + " " + studentas.Pav + " " + to_string(studentas.med) + "\n";
            /*output << std::setw(20) << std::left << mokinys[i].Vard
                << std::setw(20) << std::left << mokinys[i].Pav
                << std::setw(18) << std::left << "----"
                << mokinys[i].med << std::endl;*/
        }
        else {
            output << studentas.Vard + " " + studentas.Pav + " " + to_string(studentas.GP) + "\n";
            /*output << std::setw(20) << std::left << mokinys[i].Vard
                << std::setw(20) << std::left << mokinys[i].Pav
                << std::setw(18) << std::left << mokinys[i].GP
                << "---" << std::endl;*/
        }
    }
    output << "\n\n";
}

void textgenerator(string filename, int n) {
    string header;
    ofstream output;
    output.open(filename);
    output << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde";
    for (int i = 0; i < 15; i++) {
        string nd = to_string(i + 1);
        output << setw(8) << left << "ND" + nd;
    }
    output << setw(8) << left << "Egz." << endl;
    for (int i = 0; i < n; i++) {
        string nr = to_string(i + 1);
        output << setw(20) << left << "Vardas" + nr
            << setw(20) << left << "Pavarde" + nr;
        for (int j = 0; j < 15; j++) {
            int balas = 1 + rand() % 10;
            output << setw(8) << left << balas;
        }
        int egz = 1 + rand() % 10;
        output << setw(8) << left << egz << endl;
    }
}

unsigned int countWordsInString(std::string const& str)
{
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}

void read_from_file(list<studentas>& Eil, int pazymiu_sk, string filename)
{
    int student_counter = 0;
    int temp;
    ifstream fileRead;
    string buff;
    fileRead.open(filename);
    if (fileRead.is_open())
    {
        getline(fileRead >> ws, buff);
        pazymiu_sk = countWordsInString(buff) - 3;
        while (true)
        {

            studentas stud;
            Eil.resize(Eil.size() + 1);
            fileRead >> stud.Vard;
            if (fileRead.eof()) { Eil.pop_back(); break; }
            fileRead >> stud.Pav;
            for (int i = 0; i < pazymiu_sk; i++)
            {
                fileRead >> temp;
                stud.paz.push_back(temp);
            }
            fileRead >> stud.egz;

            int suma = 0;
            for (int i = 0; i < pazymiu_sk; i++)
            {
                suma += stud.paz[i];
            }
            
            stud.GP = suma / pazymiu_sk;
            stud.GP = stud.GP * 0.4 + 0.6 * stud.egz;
            student_counter++;
            Eil.push_back(stud);
        }

    }
    else { std::cout << "-\n"; }

}
