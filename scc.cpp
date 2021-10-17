#include "scc.hpp"

////////////////////////////////////////////////////////////////////

void DFS(int nr, vector<int> C[], bool visited[], stack<int>* stos){
    visited[nr] = true;
    for(int i = 0; i < C[nr].size(); i++){
        if(!visited[C[nr][i]]) DFS(C[nr][i], C, visited, stos);
    }
    stos->push(nr);
}

void DFSscc(int nr, int S, bool visited[], vector<int> scc[], vector<int> D[]){
    visited[nr] = true;
    scc[S].push_back(nr);
    for(int i = 0; i < D[nr].size(); i++){
        if(!visited[D[nr][i]]) DFSscc(D[nr][i], S, visited, scc, D);
    }
}

int SCC(int n, vector<int> C[], vector<int> D[], vector<int> scc[]){
    bool visited[n+2];
    stack <int> stos;
    int com = 0;
    for(int i = 0; i <= n; i++) visited[i] = false; 
    for(int i = 1; i<=n; i++){
        if(!visited[i]) DFS(i, C, visited, &stos);
    }
    for(int i = 0; i <= n; i++) visited[i] = false; 

    while(!stos.empty()){
        int akt = stos.top();
        stos.pop();
        
        if(!visited[akt]) {
            com ++;
            DFSscc(akt, com, visited, scc, D);
        }
    } 

    return com;
}

////////////////////////////////////////////////////////////////////