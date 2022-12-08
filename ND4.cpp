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
    int N = 1000;
    cout << "Ar norite is naujo sugeneruoti file (Y) ar naudoti jau turima (N)?\n";
    char x;
    cin >> x;
    x = toupper(x);
    while (x != 'N' && x != 'Y') {
        cout << "Klaida, iveskite N arba Y ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> x;
    }
    if (x == 'Y') {
        cout << "Keliu studentu duomenu norite?\n";
        int a;
        cin >> a;
        while (cin.fail()) {
            cout << "Klaida, iveskite skaiciu  ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> a;
        }
        chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        textgenerator("test.txt", a);
        chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        //cout << "Teksto generavimui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    }
    
    cout << "LIST\n";

        list <studentas> all_students1;
        vector <studentas> all_students2;

        chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        read_from_file_list(all_students1, 15, "test.txt");
        chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        cout << "Teksto nuskaitymui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

        begin = std::chrono::steady_clock::now();

        list <studentas> vargsiukai1;
        list <studentas> galvociai1;    
        


            
                for (auto& s : all_students1) {
                    if (s.GP < 5.00) vargsiukai1.push_back(s);
                    else galvociai1.push_back(s);
                }
                
            
        
        end = std::chrono::steady_clock::now();
        cout << "Teksto rusiavimui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

        begin = std::chrono::steady_clock::now();
        print_student_list(vargsiukai1, 15, "Vargsiukai.txt");
        print_student_list(galvociai1, 15, "Galvociai.txt");
        end = std::chrono::steady_clock::now();
        //cout << "Teksto isvedimui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        cout << "VECTOR\n";

        begin = std::chrono::steady_clock::now();
        read_from_file_vector(all_students2, 15, "test.txt");
        end = std::chrono::steady_clock::now();
        cout << "Teksto nuskaitymui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

        begin = std::chrono::steady_clock::now();

        vector <studentas> vargsiukai2;
        vector <studentas> galvociai2;


        for (int i = 0; i < all_students2.size(); i++) {
            studentas stud = all_students2[i];
            if (stud.GP <= 5) {
                vargsiukai2.push_back(stud);
            }
            else {
                galvociai2.push_back(stud);
            }
        }

        end = std::chrono::steady_clock::now();
        cout << "Teksto rusiavimui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

        begin = std::chrono::steady_clock::now();
        print_student_vector(vargsiukai2, 15, "Vargsiukai_VECTOR.txt");
        print_student_vector(galvociai2, 15, "Galvociai_VECTOR.txt");
        end = std::chrono::steady_clock::now();
        //cout << "Teksto isvedimui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;


    

}
    
