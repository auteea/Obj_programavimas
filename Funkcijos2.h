#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>
#include "Studentas2.h"

using namespace std;

float count_median(std::vector<int> pazymiai);

void print_student(std::vector<studentas> Eil, int pazymiu_sk);

unsigned int countWordsInString(std::string const& str);

void read_from_file(std::vector<studentas>& Eil, int* pazymiu_sk);

vector<studentas> ivedimas();