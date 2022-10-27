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

#include "Funkcijos3.h"
#include "Studentas3.h"

using namespace std;

void print_student(vector<studentas> mokinys, int pazymiu_sk, string filename) {
    ofstream output;
    output.open(filename);
    output << std::setw(20) << std::left << "Vardas"
        << std::setw(20) << std::left << "Pavarde"
        << std::setw(18) << std::left << "Galutinis\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < mokinys.size(); i++)
    {
        if (mokinys[i].ivestis == "") {
            output << std::setw(20) << std::left << mokinys[i].Vard
                << std::setw(20) << std::left << mokinys[i].Pav
                << std::setw(18) << std::left << mokinys[i].GP;
        }
        else if (mokinys[i].ivestis == "0") {
            output << std::setw(20) << std::left << mokinys[i].Vard
                << std::setw(20) << std::left << mokinys[i].Pav
                << std::setw(18) << std::left << "----"
                << mokinys[i].med << std::endl;
        }
        else {
            output << std::setw(20) << std::left << mokinys[i].Vard
                << std::setw(20) << std::left << mokinys[i].Pav
                << std::setw(18) << std::left << mokinys[i].GP
                << "---" << std::endl;
        }
    }
    output << "\n\n";
}

void textgenerator(string filename, int n) {
    string header;
    ofstream output;
    output.open(filename);
    output << std::setw(20) << std::left << "Vardas"
        << std::setw(20) << std::left << "Pavarde";
    for (int i = 0; i < 15; i++) {
        string nd = std::to_string(i + 1);
        output << std::setw(8) << std::left << "ND" + nd;
    }
    output << setw(8) << left << "Egz." << endl;
    for (int i = 0; i < n; i++) {
        string nr = std::to_string(i + 1);
        output << std::setw(20) << std::left << "Vardas" + nr
            << std::setw(20) << std::left << "Pavarde" + nr;
        for (int j = 0; j < 15; j++) {
            int balas = 1 + rand() % 10;
            output << std::setw(8) << std::left << balas;
        }
        int egz = 1 + rand() % 10;
        output << setw(8) << left << egz << endl;
    }
}

unsigned int countWordsInString(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

void read_from_file(vector<studentas>& Eil, int pazymiu_sk, string filename)
{
    int student_counter = 0;
    int temp;
    std::ifstream fileRead;
    std::string buff;
    fileRead.open(filename);
    if (fileRead.is_open())
    {
        getline(fileRead >> std::ws, buff);
        pazymiu_sk = countWordsInString(buff) - 3;
        while (true)
        {

            Eil.resize(Eil.size() + 1);
            fileRead >> Eil.at(student_counter).Vard;
            if (fileRead.eof()) { Eil.pop_back(); break; }
            fileRead >> Eil.at(student_counter).Pav;
            for (int i = 0; i < pazymiu_sk; i++)
            {
                fileRead >> temp;
                Eil.at(student_counter).paz.push_back(temp);
            }
            fileRead >> Eil.at(student_counter).egz;
            Eil.at(student_counter).GP = Eil.at(student_counter).GP / pazymiu_sk;
            Eil.at(student_counter).GP = Eil.at(student_counter).GP * 0.4 + 0.6 * Eil.at(student_counter).egz;
            student_counter++;
        }

    }
    else { std::cout << "-\n"; }
}
