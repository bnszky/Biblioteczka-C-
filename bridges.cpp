#include <bits/stdc++.h> 
using namespace std;
#define N 100005

bool visited[N];
int preorder[N];
int low[N];
int t = 0;
vector <int> node[N];
int n,m;
int SIZE;

//---------------------------------------------//

int bridges(int nr, int from, vector <pair <int,int>> *edges = NULL){

visited[nr] = true;
preorder[nr] = t;
int l = t;
t++;

for(int i = 0; i < node[nr].size(); i++) {
    if(!visited[node[nr][i]]) 
        l = min(l, bridges(node[nr][i], nr, edges));
    else if(node[nr][i] != from) l = min(l, preorder[node[nr][i]]);
}

low[nr] = l;

if(edges != NULL && low[nr] == preorder[nr] && nr != 1)
    edges->push_back({from, nr});

return l;

}

void find_components(int nr, int from, stack <pair <int,int>> *S, vector <pair <int, int>> V[]){

visited[nr] = true;
stack <pair <int, int>> help;
for(int i = 0; i < node[nr].size(); i++){
    if(!visited[node[nr][i]]) {
        S->push({nr, node[nr][i]});
        find_components(node[nr][i], nr, S, V);

        if(low[node[nr][i]] >= preorder[nr]) {
            SIZE ++;
            while(!S->empty()){
                pair <int, int> A = S->top();
                S->pop();

                V[SIZE].push_back(A);
                if(A.first == nr && A.second == node[nr][i]) break;
            }
        }
    }    
    else if(node[nr][i] != from && preorder[nr] > preorder[node[nr][i]]){
        help.push({nr, node[nr][i]});
    }
}

while(!help.empty()) {S->push(help.top()); help.pop();}

}



int biconnected_components(vector <pair <int, int>> V[]){
    bridges(1, -1);
    stack <pair <int, int>> S;
    fill(visited, visited + n + 1, 0);
    find_components(1, -1, &S, V);
    return SIZE;
}

void articulation_points(int nr, stack <int> *S){

visited[nr] = true;
int maxi = -1;
int childs = 0;
for(int i = 0; i < node[nr].size(); i++){
    if(!visited[node[nr][i]]){
        childs++;
        maxi = max(maxi, low[node[nr][i]]);
        articulation_points(node[nr][i], S);
    }
}

if((nr == 1 && childs >= 2) 
|| (nr != 1 && maxi >= preorder[nr])) S->push(nr);

}

int main(){

vector <pair <int,int>> Q[N];
stack <int> points;
cin >> n >> m;
cout << m << "\n";
for(int i = 0; i < m; i++){
    int a,b; cin >> a >> b;
    cout << a << " " << b << "\n";
    node[a].push_back(b); node[b].push_back(a);
}

biconnected_components(Q);
fill(visited, visited+n+1, 0);
articulation_points(1, &points);

cout << SIZE << "\n";
for(int i = 1; i <= SIZE; i++){
    cout << Q[i].size() << "\n";
    for(int j = 0; j < Q[i].size(); j++){
        cout << Q[i][j].first << " " << Q[i][j].second << "\n";
    }
}

cout << points.size() << "\n";
while(!points.empty()){
    cout << points.top() << "\n";
    points.pop();
}

}