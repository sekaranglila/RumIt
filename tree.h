#ifndef tree_h
#define tree_h

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct tNode *AddressTree;
typedef struct tNode {
	int Info;
	AddressTree Left;
	AddressTree Right;
} Node;
typedef AddressTree BinTree;

#define Akar(P) (P)->Info
#define Left(P) (P)->Left
#define Right(P) (P)->Right
#define Nil NULL

BinTree Tree (int Akar, BinTree L, BinTree R);
// fungsi untuk membentuk pohon

bool IsTreeEmpty (BinTree P);
// mengembalikan true jika pohon kosong, false jika tidak

bool IsOneElmt (BinTree P);
// mengembalikan true jika pohon hanya memiliki satu elemen, false jika tidak

void PrintTree (BinTree P, int h);
// mencetak isi dari pohon

bool SearchTree (BinTree P, int X);
// mengembalikan true jika X ada di dalam tree, false jika tidak

string DaunToBits (BinTree P, long long X);
// mengembalikan bits berdasarkan daun X, 0 jika ke kiri, 1 jika ke kanan

#endif // tree_h
