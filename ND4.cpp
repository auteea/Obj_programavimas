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
#include <cctype>
#include "Funkcijos4.h"
#include "Studentas4.h"


using namespace std;


int main() {
    cout << "Ar norite is naujo sugeneruoti file (Y) ar naudoti jau turima (N)?\n";
    char x;
    cin >> x;
    while (toupper(x) != 'N' && toupper(x) != 'Y') {
        cout << "Klaida, iveskite N arba Y ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> x;
    }
    if (x == 'Y') {
        cout << "Keliu studentu duomenu norite?\n";
        int a;
        cin >> a;
        chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        textgenerator("test.txt", a);
        chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        cout << "Teksto generavimui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    }
    
        //vector <studentas> all_students;
        list <studentas> all_students;


        chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        read_from_file(all_students, 15, "test.txt");
        chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        cout << "Teksto nuskaitymui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

        begin = std::chrono::steady_clock::now();

        list <studentas> vargsiukai;
        list <studentas> galvociai;

      
        

            for (int i = 0; i < all_students.size(); i++) {
                studentas stud = get(all_students, i);
                if (stud.GP <= 5) {
                    vargsiukai.push_back(stud);
                }
                else {
                    galvociai.push_back(stud);
                }
            }
        

        end = std::chrono::steady_clock::now();
        cout << "Teksto rusiavimui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

        begin = std::chrono::steady_clock::now();
        print_student(vargsiukai, 15, "Vargsiukai.txt");
        print_student(galvociai, 15, "Galvociai.txt");
        end = std::chrono::steady_clock::now();
        cout << "Teksto isvedimui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    

}
    
