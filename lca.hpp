#ifndef lca_hpp
#define lca_hpp
#include <bits/stdc++.h>
using namespace std;

struct LCA;

void initialize(vector <pair <int, long long>> A[], int am);
int find(int a, int b);
long long distance(int a, int b, long long sums[]);

#endif