#include "huffman.h"

long long Pow (int a, int b) {
    int ans = 1;

    for (int i=1; i<=b; i++) {
        ans = ans * a;
    }
    return ans;
}

bool IsAsciiOneElmt (asciiArr arr) {
    long long count = 0;

    for (int i=0; i<256; i++) {
        if (arr.ascii[i] != 0) {
            count++;
        }
    }
    return (count == 1);
}

unsigned int ByteToDecimal(string s) {
    int i;
    unsigned int ans;

    ans = 0;
    for (i=0; i<8; i++) {
        if (s[i] == '1') {
            ans = ans + Pow(2,7-i);
        }
    }
    return ans;
}

string IntToString (int a) {
    string s;
    int temp;

    while (a != 0) {
        temp = a % 10;
        a = a/10;
        switch (temp) {
            case 1 : s = '1' + s; break;
            case 2 : s = '2' + s; break;
            case 3 : s = '3' + s; break;
            case 4 : s = '4' + s; break;
            case 5 : s = '5' + s; break;
            case 6 : s = '6' + s; break;
            case 7 : s = '7' + s; break;
            case 8 : s = '8' + s; break;
            case 9 : s = '9' + s; break;
            case 0 : s = '0' + s; break;
        }
    }
    return s;
}

int CharToInt (char X) {
    switch (X) {
        case '1' : return 1;
        case '2' : return 2;
        case '3' : return 3;
        case '4' : return 4;
        case '5' : return 5;
        case '6' : return 6;
        case '7' : return 7;
        case '8' : return 8;
        case '9' : return 9;
        case '0' : return 0;
    }
}

string CharToBinary (char c) {
    string s;

    for (int i = 7; i >= 0; --i) {
        if (c&(1 << i)) {
            s = s + '1';
        }
        else {
            s = s + '0';
        }
    }
    return s;
}

int GetFileSize(string filename) {
    FILE *f = Nil;
    f = fopen(filename.c_str(), "rb");
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    fclose(f);
    return size;
}

void countEBPS (unsigned long long asciix[256], string bitCompress[256], double *entropi, double *bitPerSimbol) {
    int total = 0;
    int i;
    double peluang[256];

    *entropi = 0;
    for (i=0; i<256; i++) {
        total = total + asciix[i];
    }
    for (i=0; i<256; i++) {
        peluang[i] = (double) asciix[i] / (double) total;
        if (peluang[i] != 0.00) {
            *entropi = *entropi + (-1 * peluang[i] * log2(peluang[i]));
            *bitPerSimbol = *bitPerSimbol + (peluang[i] * (double) bitCompress[i].length());
        }
    }
}
