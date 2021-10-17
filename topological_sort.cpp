#include "topological_sort.hpp"

void topological_sort(vector <int> newG[], vector <int> newH[], stack <int>* S, int SIZE){
    queue <int> Q;
    int in[SIZE+1];
    bool P[SIZE+1];
    for(int i = 0; i<SIZE; i++) P[i] = false;
    for(int i = 1; i<= SIZE; i++){
        in[i] = newH[i].size();
        if(in[i] == 0) {Q.push(i); P[i] = true;}
    }
    while(!Q.empty()){
        int nr = Q.front();
        S->push(nr);
        Q.pop();
        for(int i = 0; i < newG[nr].size(); i++){
            int akt = newG[nr][i];
            in[akt] --;
            if(in[akt] <= 0 && !P[akt]) {Q.push(akt); P[akt] = true;}
        }
    }
}