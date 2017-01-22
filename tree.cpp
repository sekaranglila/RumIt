#include "tree.h"

BinTree Tree (int Akar, BinTree L, BinTree R) {
    AddressTree P;

    P = (AddressTree) malloc (sizeof(Node));
    if (P != Nil) {
        Akar(P) = Akar;
        Left(P) = L;
        Right(P) = R;
        return P;
    }
    else {
        return Nil;
    }
}

bool IsTreeEmpty (BinTree P) {
    if (P == Nil) {
        return true;
    }
    else {
        return false;
    }
}

bool IsOneElmt (BinTree P) {
    if (IsTreeEmpty(P)) {
        return false;
    }
    else {
        if ((Left(P) == Nil) && (Right(P) == Nil)) {
            return true;
        }
        else {
            return false;
        }
    }
}

void PrintTree (BinTree P, int h) {
    int i;

    if (IsTreeEmpty(P)) {
        cout << "." << endl;
    }
    else {
        cout << Akar(P) << endl;
        for (i=1; i<=h; i++) {
            cout << " ";
        }
        PrintTree(Left(P), h*2);
        for (i=1; i<=h; i++) {
            cout << " ";
        }
        PrintTree(Right(P), h*2);
    }
}

bool SearchTree (BinTree P, int X) {
    if (IsTreeEmpty(P)) {
        return false;
    }
    else if (Akar(P) == X) {
        return true;
    }
    else {
        return ((SearchTree(Left(P),X)) || (SearchTree(Right(P),X)));
    }
}

string DaunToBits (BinTree P, long long X) {
    string s;

    while (Akar(P) != X) {
        if (SearchTree(Left(P), X)) {
            P = Left(P);
            s = s + '0';
        }
        else {
            P = Right(P);
            s = s + '1';
        }
    }
    return s;
}
