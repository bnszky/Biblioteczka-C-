#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int INF = INT_MAX;

struct BipGraph{

int n, m;
vector < vector<int> > adj;
vector <int> l,r, dist;

BipGraph(int, int);
void AddEdge(int, int);
bool BFS();
bool DFS(int);
int HopcroftKarp();

};

BipGraph::BipGraph(int n, int m){
    this->n = n; this->m = m;
    adj.resize(n+1);
    dist.resize(n+1);
    l.resize(n+1); r.resize(m+1);
}

void BipGraph::AddEdge(int u, int v){
    adj[u].pb(v);
}

bool BipGraph::BFS(){

queue <int> Q;

for(int u = 1; u<=n; u++){
    if(!l[u]) {
        dist[u] = 0;
        Q.push(u);
    }
    else dist[u] = INF;
}
dist[0] = INF;

while(!Q.empty()){

int u = Q.front(); Q.pop();
if(dist[u] < dist[0]){
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(dist[r[v]] == INF){
            dist[r[v]] = dist[u] + 1;
            Q.push(r[v]);
        }
    }
}

}

return (dist[0] != INF);

}

bool BipGraph::DFS(int u){

if(u){

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if((dist[r[v]] == dist[u] + 1) and DFS(r[v])){
            l[u] = v; r[v] = u;
            return true;
        }
    }
    dist[u] = INF;
    return false;
}
return true;

}

int BipGraph::HopcroftKarp(){

int result = 0;

while(BFS()){
    for(int i = 1; i <= n; i++){
        if(!l[i] and DFS(i))
            result++;
    }
}

return result;

}

void WriteEdges(int n, int m, BipGraph graph){

for(int i = 1; i <= n; i++){
    if(graph.l[i]) cout << i << " - " << graph.l[i] + n << "\n";
}

}

int main(){

ios_base::sync_with_stdio(false);
cin.tie(nullptr); cout.tie(nullptr);

int n, m, k;
cin >> n >> m >> k;
BipGraph graph(n,m);

for(int i = 0; i < k; i++) {
    int u,v; cin >> u >> v;
    graph.AddEdge(u, v-n);
}

cout << "Maximum Matching: " << graph.HopcroftKarp() << "\n";

WriteEdges(n,m,graph);

}
