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

#include "Funkcijos5.h"
#include "Studentas5.h"


using namespace std;


int main() {
    int N = 1000;
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
        //cout << "Teksto generavimui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    }
    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            cout << "1 strategija\n";
        }
        else {
            cout << "2 strategija\n";
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

        
        if (i == 0) {
            
            for (auto& s : all_students1) {
                if (s.GP < 5.00) vargsiukai1.push_back(s);
                else galvociai1.push_back(s);
            }
        }
        else {
            for (auto& s : all_students1) {
                vargsiukai1.push_back(s);
              
            }
            all_students1.erase(std::remove_if(all_students1.begin(), all_students1.end(), [](const studentas& x) {
                return x.GP <= 5;
                }), all_students1.end());
        }

        end = std::chrono::steady_clock::now();
        cout << "Teksto rusiavimui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

        begin = std::chrono::steady_clock::now();
        if (i == 0) {
            print_student_list(vargsiukai1, 15, "Vargsiukai.txt");
            print_student_list(galvociai1, 15, "Galvociai.txt");            
        }
        else {
            print_student_list(vargsiukai1, 15, "Vargsiukai.txt");
            print_student_list(all_students1, 15, "Galvociai.txt");
           
        }
        
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

           

        if (i == 0) {
            for (int i = 0; i < all_students2.size(); i++) {
                studentas stud = all_students2[i];
                if (stud.GP <= 5) {
                    vargsiukai2.push_back(stud);
                }
                else {
                    galvociai2.push_back(stud);
                }
            }
            
        }
        else {
            for (int i = 0; i < all_students2.size(); i++) {
                studentas stud = all_students2[i];
                if (stud.GP <= 5) {
                    vargsiukai2.push_back(stud);
                }
                
            }
            for (int i = 0; i < all_students2.size(); i++) {
                studentas stud = all_students2[i];
                if (stud.GP > 5) {
                    all_students2.erase(all_students2.begin()+i);
                }
                
            }
            
        }
        end = std::chrono::steady_clock::now();
        cout << "Teksto rusiavimui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

        begin = std::chrono::steady_clock::now();
        if (i == 0) {
            print_student_vector(vargsiukai2, 15, "Vargsiukai_VECTOR.txt");
            print_student_vector(galvociai2, 15, "Galvociai_VECTOR.txt");
        }
        else {
            print_student_vector(vargsiukai2, 15, "Vargsiukai_VECTOR.txt");
            print_student_vector(all_students2, 15, "Galvociai_VECTOR.txt");

        }
        
        end = std::chrono::steady_clock::now();
        //cout << "Teksto isvedimui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;



    }
}

