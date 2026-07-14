#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>

unsigned int NSD(unsigned int a, unsigned int b);

bool nesoudelna(unsigned int a, unsigned int b);

void generovani_prvocisel(int &p, int &q);

void generovani_klice();

unsigned long long sifrovani(unsigned long long cislo, unsigned long long exponent, unsigned long long N);
