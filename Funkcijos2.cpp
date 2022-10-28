
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
#include "Studentas2.h"
#include "Funkcijos2.h"

using namespace std;


void print_student(std::vector<studentas> Eil, int pazymiu_sk) {
    ofstream output;
    output.open("rezultatai.txt");
    output << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < Eil.size(); i++)
    {
        if (Eil[i].ivestis == "0") {
            output << setw(20) << left << Eil[i].Vard
                << setw(20) << left << Eil[i].Pav
                << setw(18) << left << "----"
                << setprecision(3) << Eil[i].med << endl;
        }
        else {
            output << setw(20) << left << Eil[i].Vard
                << setw(20) << left << Eil[i].Pav
                << setw(18) << left << setprecision(3) << Eil[i].GP
                << "----" << endl;
        }
    }
    output << "\n\n";
}

unsigned int countWordsInString(string const& str)
{
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}

void read_from_file(vector<studentas>& Eil, int* pazymiu_sk, string filename)
{
    int student_counter = 0;
    int temp;
    ifstream fileRead;
    string buff;
    fileRead.open(filename);
    if (fileRead.is_open())
    {
        getline(fileRead >> ws, buff);
        *pazymiu_sk = countWordsInString(buff) - 3;
        while (true)
        {
            Eil.resize(Eil.size() + 1);
            fileRead >> Eil.at(student_counter).Vard;
            if (fileRead.eof()) {
                Eil.pop_back();
                break;
            }
            fileRead >> Eil.at(student_counter).Pav;
            for (int i = 0; i < *pazymiu_sk; i++)
            {
                fileRead >> temp;
                Eil.at(student_counter).paz.push_back(temp);
            }
            fileRead >> Eil.at(student_counter).egz;
            Eil.at(student_counter).GP = Eil.at(student_counter).GP / *pazymiu_sk;
            Eil.at(student_counter).GP = Eil.at(student_counter).GP * 0.4 + 0.6 * Eil.at(student_counter).egz;
            student_counter++;
            
        }
    
    }
    else { cout << "-\n"; }
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
        cout << "Pavarde: ";
        cin >> stud.Pav;
        string generuoja;
        cout << "Jei norite ivesti pazymius pats spauskite 0 , jei nenorite spauskite bet kuri kita mygtuka  ";
        cin >> generuoja;
        if (generuoja != "0") {
            cout << "Egzamino pazymys: ";
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
            cout << "Egzamino pazymys: ";
            int egzaminas;
            cin >> egzaminas;
            while (cin.fail() || egzaminas < 1 || egzaminas>10) {
                cout << "Klaida, iveskite skaiciu ne didesni uz 10  ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> egzaminas;
            }
            stud.egz = egzaminas;
            cout << i + 1 << "-ojo studento nd pazymiai, kai noresite sustoti, irasykite 0: \n";
            int x = 1;
            cin >> x;
            while (cin.fail() || x < 0 || x>10) {
                cout << "Klaida, iveskite teigiama skaiciu, mazesni uz 10 (arba 0) ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> x;
            }
            while (x != 0) {
                stud.paz.push_back(x);
                cin >> x;
                while (cin.fail() || x < 0 || x>10) {
                    cout << "Klaida, iveskite teigiama skaiciu, mazesni uz 10 (arba 0) ";
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
            else { 
                mediana = ((float)stud.paz[c / 2 - 1] + (float)stud.paz[c / 2]) / 2; }
        }
        stud.med = mediana * 0.4 + 0.6 * stud.egz;
        if (c == 0) stud.GP = 0.6 * stud.egz;
        else {
            float suma = 0;
            suma = accumulate(stud.paz.begin(), stud.paz.end(), 0);
            float vid = suma / c;
            stud.GP = vid * 0.4 + 0.6 * stud.egz;
            
        }
        cout << "\nJei noresite gauti galutini pazymi pagal mediana spauskite: 0 \njei pagal vidurki: bet ka kita.\n";
        string ivestis;
        cin >> ivestis;
        stud.ivestis = ivestis;

        grupe.push_back(stud);
        stud.paz.clear();
    }
    return grupe;
}
