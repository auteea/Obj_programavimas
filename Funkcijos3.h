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

#include "Studentas3.h"

using namespace std;
void textgenerator(string filename, int n);
unsigned int countWordsInString(std::string const& str);
void read_from_file(std::vector<studentas>& Eil, int pazymiu_sk, string filename);
void print_student(vector<studentas> Eil, int pazymiu_sk, string filename);
