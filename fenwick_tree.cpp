#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define K 1005

namespace fenwick{
int pref[N];

ll get(int x){

ll result = 0;
for(x; x>0; x-=(x&(-x)))
    result += pref[x];
return result;  

}

ll get(int l, int r){
    l = l*2-1; r = r*2-1;
    return (get(r) - get(l-1));
}

void add(int x, ll val){

    x = x*2-1;
    for(x; x<N; x+=(x&(-x)))
        pref[x] += val;
}

};

namespace fenwick2D{
ll pref[K][K];

ll get(int x, int y){

    ll result = 0;
    for(int i = y; i > 0; i-=(i&(-i)))
        for(int j = x; j > 0; j-=(j&(-j)))
            result += pref[i][j];
    return result;

}

ll get(int x1, int y1, int x2, int y2){

   x1 = x1*2-1; x2 = x2*2-1; y1 = y1*2-1; y2 = y2*2-1;
   return (
       get(x2, y2) + get(x1-1, y1-1) - get(x2, y1-1) - get(x1-1, y2)
   ) ;
    
}

void add(int x, int y, ll val){

x = x*2-1; y = y*2-1;
for(int i = y; i < K; i+=(i&(-i)))
        for(int j = x; j < K; j+=(j&(-j)))
            pref[i][j] += val;

}

void write(int n){
    cout << "Macierz: \n";
    n*=2;
    for(int i = 1; i < n; i+=2){
        for(int j = 1; j < n; j+=2)
            cout << pref[i][j] << " ";
        cout << "\n";
    }
}

}

void random_numbers(int n, int k){

    for(int i = 0; i < n; i++){
        int x = rand()%k + 1;
        int y = rand()%k + 1;
        int val = rand()%10;
        cout << "ADD: {" << x << ", " << y << "} val=" << val << "\n";

        fenwick2D::add(x, y, val);
    }

}

int main(){

random_numbers(10, 10);
fenwick2D::write(10);

int n;
cin >> n;
for(int i = 0; i < n; i++){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << "Sum: " << fenwick2D::get(a,b,c,d) << "\n";
}

}