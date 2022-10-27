// mano mas DB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<random>

using namespace std;

struct studentas {
	string Vard = "", Pav = "", isved = "";
	int nd[30], egz;
	float GP = 0, med;
};

int main()
{
	vector<studentas> grupe;
	studentas stud;
	cout << "Iveskite studentu skaiciu: ";
	int studentukiekis;
	cin >> studentukiekis;
	while (cin.fail()) {
		cout << "Klaida, iveskite skaiciu!";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> studentukiekis;
	}
	grupe.reserve(studentukiekis);

	for (int i = 0; i < studentukiekis; i++) {
		stud.GP = 0;
		cout << "Iveskite " << i + 1 << "-aji varda: ";
		cin >> stud.Vard;
		cout << "Pavarde: ";
		cin >> stud.Pav;
		cout << "Jei norite pazymius ivesti pats, spauskite 0, jei nenorite, spauskite bet kuri kita mygtuka.\n";
		string generuoja;
		cin >> generuoja;

		int j = 0;

		if (generuoja != "0") {
			cout << "Egzamino pazymys: ";
			stud.egz = 1 + (rand() % 10);
			cout << stud.egz << "\n";
			string x = "x";
			cout << i + 1 << "-ojo studento nd pazymiai, kai noresite sustoti, irasykite 0: \n";
			while (x != "0") {
				int a = 1 + rand() % 10;
				cout << a << "		";
				stud.nd[j] = a;
				stud.GP = stud.GP + (float)stud.nd[j];
				j++;
				cin >> x;
			}
		}
		else {
			cout << "Egzamino pazymys: \n";
			int egzaminas;
			cin >> egzaminas;
			while (cin.fail() || egzaminas < 1 || egzaminas>10) {
				cout << "Klaida, iveskite skaiciu ne didesni uz 10!\n";
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
				stud.nd[j] = x;
				stud.GP = stud.GP + (float)stud.nd[j];
				j++;
				cin >> x;
				while (cin.fail() || x < 0 || x>10) {
					cout << "klaida, iveskite teigiama skaiciu, mazesni uz 10 (arba 0) ";
					cin.clear();
					cin.ignore(256, '\n');
					cin >> x;
				}
			}

		}
		std::sort(stud.nd, stud.nd + j);
		cout << "\n" << "Studento pazymiai: \n";
		for (int i = 0; i < j; i++)	cout << stud.nd[i] << " "; cout << "\n";
		float mediana;
		if (j % 2 == 0)
			mediana = ((float)stud.nd[j / 2 - 1] + (float)stud.nd[j / 2]) / 2;
		else {
			int laik = j / 2 + 0.5;
			mediana = stud.nd[laik];
		}
		stud.med = mediana * 0.4 + 0.6 * stud.egz;
		if (j == 0) stud.GP = 0.6 * stud.egz;
		else {
			stud.GP = stud.GP / j;
			//cout << '\n' << stud.GP << '\n';
			stud.GP = stud.GP * 0.4 + 0.6 * stud.egz;
		}
		cout << "Ar norite, kad isvestu galutini pazymi pagal vidurki (0) ar mediana (bet koks kitas zenklas)?\n";
		string pasirinkimas;
		cin >> pasirinkimas;
		stud.isved = pasirinkimas;
		grupe.push_back(stud);
	}

	cout << std::left << setw(20) << "Vardas" << setw(20) << "Pavarde" << "Galutinis (Vid.)\t\t\Galutinis (Med.)\n";
	cout << "--------------------------------------------------------------------------------------------------\n";

	for (auto& tt : grupe) {
		cout << setw(20) << tt.Vard << setw(20) << tt.Pav;

		if (tt.isved != "0") 	cout << setw(20) << "----" << setw(20) << setprecision(2) << fixed << tt.med << "\n";
		else   cout << setw(20) << setprecision(2) << fixed << tt.GP << "\n";
	}
	grupe.clear();
	char a;
	cin >> a;


	
}