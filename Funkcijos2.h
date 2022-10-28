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

void print_student(vector<studentas> Eil, int pazymiu_sk);

unsigned int countWordsInString(std::string const& str);

void read_from_file(vector<studentas>& Eil, int* pazymiu_sk, string filename);

vector<studentas> ivedimas();
