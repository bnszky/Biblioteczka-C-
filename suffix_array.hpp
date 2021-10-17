#ifndef suffix_array_hpp
#define suffix_array_hpp
#include <bits/stdc++.h>

using namespace std;

namespace SA{

long long diff_subwords(int[], long long); // lcp, nap.size()
void LCP(string, int[], int[], int[]); // nap, sa, rank, lcp
void building_SA_with_KMR(string, int[], int[]); // nap, rank, sa

};

#endif