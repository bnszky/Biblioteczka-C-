// plik main.cpp do testowania algorytmow
#include <bits/stdc++.h>
using namespace std;

// pamietaj zeby zaimplementowac potrzebny plik z odpowiadajacym algorytmem .cpp
#include "manacher.cpp"
#include "scc.cpp"
#include "lca.cpp"
#include "suffix_array.cpp"
#include "monotonic_queue.cpp"
//

monotonic_queue <int> kolejka;

int main(){

	kolejka.push(4); kolejka.push(2);
	cout << kolejka.min() << " " << kolejka.front() << "\n";
}