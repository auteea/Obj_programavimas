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

int main() {
    chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    vector <studentas> all_students;
    textgenerator("test.txt", 10000);
    chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "Teksto generavimui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    read_from_file(all_students, 15, "test.txt");
    end = std::chrono::steady_clock::now();
    cout << "Teksto nuskaitymui prireike = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    vector <studentas> vargsiukai;
    vector <studentas> galvociai;
    for (int i = 0; i < all_students.size(); i++) {
        if (all_students[i].GP <= 5) {
            vargsiukai.push_back(all_students[i]);
        }
        else {
            galvociai.push_back(all_students[i]);
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
