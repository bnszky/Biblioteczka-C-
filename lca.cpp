#include "lca.hpp"

struct LCA{

    int lca[100005][17];
    int height[100005];
    int SIZE = 0;

    void initialize(vector <pair <int, long long>> A[], int am){

        //////////////////////// Obliczanie wysokosci i lca dla 2^0
        queue <pair <int, int>> Q;
        Q.push(make_pair(1,0));
        lca[1][0] = 0; lca[0][0] = 0;
        int height_max = -1;
        while(!Q.empty()){
            pair <int,int> curr = Q.front();
            height[curr.first] = curr.second;
            height_max = max(height_max, curr.second);
            Q.pop();
            if(!A[curr.first].empty()) for(int i = 0; i<A[curr.first].size(); i++){
                lca[A[curr.first][i].first][0] = curr.first;
                Q.push(make_pair(A[curr.first][i].first, curr.second + 1));
            }
        }
        ///////////////////////// DP dla lca dla n 
        SIZE = ceil(log2(height_max)) + 1;
        for(int i = 1; i<= SIZE; i++){
            for(int j = 1; j <= am; j++) {
                lca[j][i] = lca[lca[j][i-1]][i-1];
            }
        }

    }

    int find(int a, int b){
        int diff = abs(height[a] - height[b]);
        ////////////////////////// Wyrownywanie poziomow
        queue <bool> second;
        while(diff != 0){ 
            second.push(diff%2);
            diff/=2;
        }
        int start = a;
        if(height[a] < height[b]) start = b;

        int p = 0;
        while(!second.empty()){
            if(second.front()) start = lca[start][p];
            p++;
            second.pop();
        }
        if(height[a] < height[b]) b = start;
        if(height[b] < height[a]) a = start;
        ///////////////////////// Znajdowanie LCA
        if (a == b) return a;
        else {
            for(int i = SIZE; i>=0; i--){
                if(lca[a][i] != lca[b][i]) {
                    a = lca[a][i];
                    b = lca[b][i];
                }
            }
        }
        return lca[a][0];
    }

    template <class small, class big>
    big distance(small a, small b, big sums[]){
        return ( (sums[a] + sums[b]) - (2*sums[find(a,b)]) );
    }

};