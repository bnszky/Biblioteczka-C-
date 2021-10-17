#include <bits/stdc++.h>
using namespace std;

int main(){

srand(time(NULL));
int n = rand()%7 + 5;
cout << n << "\n";

for(int i = 0; i < n; i++) {
    cout << rand()%20 - 9 << " " << rand()%20 - 9 << "\n";
}
}