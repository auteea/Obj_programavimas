#pragma once
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

#include "Studentas5.h"
#include "Funkcijos5.h"

using namespace std;
studentas get(list<studentas> _list, int _i);
void textgenerator(string filename, int n);
unsigned int countWordsInString(std::string const& str);
void read_from_file_list(std::list<studentas>& Eil, int pazymiu_sk, string filename);
void read_from_file_vector(vector<studentas>& Eil, int pazymiu_sk, string filename);
void print_student_list(list<studentas> Eil, int pazymiu_sk, string filename);
void print_student_vector(vector<studentas> mokinys, int pazymiu_sk, string filename);