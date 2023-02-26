#include <iostream>
#include "Header.h"
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    setlocale(0, "");
    // пороги: матан 43 русский 45 физика 39 инфа 42. Порог для пмм 240
    int n;
    cout << "Введите количество сдающих: ";
    cin >> n;
    int* codes = new int[n];
    int** results = new int* [n];
    int* points = new int[n];
    bool* verified_amm = new bool[n];
    init(results, n);
    filling(results, n, codes);
    write(results, n, codes);
    sort_cs_phys(results, n);
    write(results, n, codes);
    selection_amm(results, n, codes, verified_amm, points);
    sort1(results, n, codes, verified_amm, points);
    sort2(results, n, codes, points);
    print_final(results, n, codes, points, verified_amm);
}
