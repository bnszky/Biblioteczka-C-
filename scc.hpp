#ifndef scc_hpp
#define scc_hpp
#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////
/*
    SCC - strongly connected components
    Algorytm znajdowania silnie spojnych skladowych w grafie skierowanym
    ©2021 Michał Banaszkiewicz
*/
/////////////////////////////////////////////////////

void DFS(int, vector<int>[], bool[], stack<int>*);
/*
    Pierwsze przejscie dfs - wypisuje do stosu odwiedzane wierzcholki 
    wedlug kolejnosci przejscia
    1 - nr aktualnego wierzcholka
    2 - tablica wektorow - forma przedstawienia grafu
    3 - visited[] - tablica z odwiedzonymi wierzcholkami
    4 - stos do ktorego trafiaja po kolei wierzcholki
*/

void DFSscc(int, int, bool[], vector<int>[]);
/*
    Zajmuje sie tworzeniem i dokladaniem wierzcholkow do jednej silnie spojnej skladowej
    1 - nr aktualnego wierzcholka
    2 - nr aktualnej spojnej skladowej
    3 - visited[]
    4 - tablica wektorow ze zbiorami silnie spojnych skladowych
    5 - tablica wektorow - graf po przetransponowaniu
*/

int SCC(int, vector<int>[], vector<int>[], vector<int>[]);
/*
    Glowna funkcja zarzadzajaca - zwraca ilosc spojnych
    oraz przetwarza podana tablice wektorow wypisujac odpowiednie wierzcholki
    w zbiorach silnie spojnej skladowej
    1 - ilosc wierzcholkow
    2 - tablica wektorow - przedstawienie grafu
    3 - tablica wektorow - przedstawienie transponowanego grafu
    4 - tablica wektorow - przedstawiajaca silnie spojne skladowe
    return - zwraca ilosc silnie spojnych skladowych (int)
*/

#endif