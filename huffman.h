#ifndef huffman_h
#define huffman_h

#include "tree.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>
using namespace std;

typedef struct {
    unsigned long long ascii[256];
    AddressTree pointing[256];
} asciiArr;

long long Pow (int a, int b);
// mengembalikan a^b

bool IsAsciiOneElmt (asciiArr arr);
// mengembalikan true jika array hanya memiliki satu indeks dengan elemen bukan 0, false jika tidak

unsigned int ByteToDecimal (string s);
// fungsi untuk mengubah 1 byte ke dalam bentuk desimal

string IntToString (int a);
// fungsi untuk mengkonversi integer ke string

int CharToInt (char X);
// fungsi untuk mengkonversi character ke integer

string CharToBinary (char c);
// fungsi untuk mengkonversi sebuah character ke dalam bentuk biner

int GetFileSize(string filename);
// fungsi untuk memperoleh size dari sebuah file

void countEBPS (unsigned long long asciix[256], string bitCompress[256], double *entropi, double *bitPerSimbol);
// prosedur untuk menghitung entropi dan R (bitPerSimbol)

#endif // huffman_h
