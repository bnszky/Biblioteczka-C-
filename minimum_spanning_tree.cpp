// Algorytm MST - Prim i Kruskal + (Union Find)
// Autor: Michał Banaszkiewicz
/*

Example:

Input:

8 16            
0 1 5 
0 3 9 
0 6 3
1 2 9 
1 4 8 
1 5 6 
1 7 7
2 3 9 
2 4 4 
2 6 5 
2 7 3
3 6 8
4 5 2 
4 6 1
5 6 6
6 7 9

Output:

KRUSKAL: 
26
4 - 6 1
4 - 5 2
0 - 6 3
2 - 7 3
2 - 4 4
0 - 1 5
3 - 6 8

PRIM: 
26
0 - 6 3
6 - 4 1
4 - 5 2
4 - 2 4
2 - 7 3
0 - 1 5
6 - 3 8

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 10005

struct Edge{
    int from;
    int to;
    ll val;
};

bool cmp(Edge a, Edge b){
    return a.val < b.val;
}

struct Cmp{
    bool operator()(const Edge a, const Edge b){
        return (a.val > b.val);
    }
};

namespace Set{

int amount[N]; int parent[N];

void Init(int n){
    std::fill(amount, amount+n-1, 1);
    for(int i = 0; i <= n; i++) parent[i] = i;
}

int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int a, int b){
    int x = Find(a);
    int y = Find(b);

    if(x!=y){
        if(amount[x] > amount[y]){
            parent[y] = x;
            amount[x] += amount[y];
        }
        else {
            parent[x] = y;
            amount[y] += amount[x];
        }
        return true;
    }
    return false;
}

}

ll Kruskal(int n, vector <Edge> edges, vector <Edge> *results){

sort(edges.begin(), edges.end(), cmp);

Set::Init(n);

ll ans = 0;

for(int i = 0; i < edges.size() and n > 1; i++){
    Edge curr = edges[i];
    if(Set::Union(curr.from, curr.to)){
        ans += curr.val;
        results->push_back(curr);
        n--;
    }
}

return ans;

}

ll Prim(int n, vector <vector <Edge>> node, vector <Edge> *results){

priority_queue <Edge, vector<Edge>, Cmp> Q;
bool visited[n+1];
fill(visited, visited+n+1, 0);

for(auto a : node[0]) Q.push(a);
visited[0] = true;
ll ans = 0;

while(!Q.empty() and n > 1){
    Edge curr = Q.top(); Q.pop();

    if(!(visited[curr.from] and visited[curr.to])){
        results->push_back(curr);
        ans += curr.val;
        n--;

        int v = ((!visited[curr.from]) ? curr.from : curr.to);
        visited[curr.from] = true; visited[curr.to] = true;

        for(auto a : node[v]) Q.push(a);
    }
}

return ans;

}

int main(){

int n, m;
cin >> n >> m;

vector <Edge> A,B;
vector <vector <Edge>> C;
C.resize(n+1);
vector <Edge> D;

for(int i = 0; i < m; i++){
    int a,b; ll c;
    cin >> a >> b >> c;
    C[a].push_back({a,b,c});
    C[b].push_back({b,a,c});
    A.push_back({a,b,c});
}

cout << "KRUSKAL: \n";
cout << Kruskal(n, A, &B) << "\n";
for(auto b : B) cout << b.from << " - " << b.to << " " << b.val << "\n";

cout << "\nPRIM: \n";
cout << Prim(n, C, &D) << "\n";
for(auto d : D) cout << d.from << " - " << d.to << " " << d.val << "\n";


}