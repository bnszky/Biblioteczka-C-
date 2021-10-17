#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int inf = INT32_MAX;

struct point{
    int x;
    int y;
};

vector <point> v;
int n;

point start = {inf, inf};

int operator*(point a, point b){
    return (a.x * b.y) - (b.x * a.y);
}
point operator-(point a, point b){
    return {a.x - b.x, a.y - b.y};
}
bool operator==(point a, point b){
    return (a.x == b.x && a.y == b.y);
}

bool sort_by_angle(point a, point b){
    if (a == start) return 1;
    if (b == start) return 0;

    return ((b-start) * (a-start) < 0);
}

int left_turn(point a, point b, point c){
    return ((b-a) * (c-a));
}

void graham_scan(stack <point> *S){

S->push(start);
point a = v[1];
for(int i = 2; i < v.size(); i++){
    while(!(S->empty()) &&  0 >= left_turn(S->top(), a, v[i])){
        a = S->top(); S->pop();
    }
    S->push(a);
    a = v[i];
}
S->push(a);

}

int main(){

cin >> n;

for(int i = 0; i < n; i++) {
    int a,b; cin >> a >> b;
    if(b < start.y || (b == start.y && a < start.x)) start = {a,b};
    v.push_back({a,b});
}

sort(v.begin(), v.end(), sort_by_angle);
cout << v.size() << "\n";
for(int i = 0; i < v.size(); i++) cout << v[i].x << " " << v[i].y << "\n";

stack <point> S;
graham_scan(&S);
cout << S.size() << "\n";
while(!S.empty()){
    cout << S.top().x << " " << S.top().y << "\n";
    S.pop();
}

}