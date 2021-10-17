#ifndef topological_sort_hpp
#define topological_sort_hpp
#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////
/*
    Topological sorting
    Sortowanie topologiczne przeprowadzane na grafie skierowanym acyklicznym
    (C) Michał Banaszkiewicz
*/
/////////////////////////////////////////////////////

void topological_sort(vector <int>[], vector <int>[], stack <int>*, int);
/*
    1 - krawedzie wychodzace z wierzcholka
    2 - krawedzie wchodzace do wierzcholka
    3 - stos ktory przechowuje wierzcholki posortowane topologicznie, 
    ale w odrotnej kolejnosci
    4 - ilosc wierzcholkow
*/

#endif