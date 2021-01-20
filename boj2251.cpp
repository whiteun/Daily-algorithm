/*
백준 2251번
물통
SILVER 1
*/
#include <iostream>
#include <algorithm>
#include <set>
#include <tuple>
#include <queue>
#include <vector>

using namespace std;
int A,B,C;
vector<int> mx ;
set<tuple<int, int, int>> visited; //abc

set<int> ans;

tuple<int, int, int> water(const vector<int>& tup, int main, int sub, int non){
    vector<int> ret(3);
    ret[non] = tup[non];
    
    if(tup[main]+tup[sub] <= mx[sub]){ //다 부을수 있을때
        ret[main] = 0;
        ret[sub] = tup[main]+tup[sub];
    }
    else{ // 다 못부을때
        ret[main] = tup[main]+tup[sub]-mx[sub];
        ret[sub] = mx[sub];
    }
    
    return {ret[0],ret[1],ret[2]};
}

void bfs(){
    queue<tuple<int, int, int>> q;
    q.emplace(0,0,C);
    visited.insert({0,0,C});

    while(!q.empty()){
        const auto [a,b,c] = q.front(); q.pop();
        if(a==0) ans.insert(c);
        
        vector<int> val = {a,b,c};
        vector<int> per = {0,1,2};
        tuple <int,int,int> nt;
        
        do{
            
            int main = per[0], sub = per[1], non = per[2];
            if(val[main] != 0  && val[sub] < mx[sub]){
                nt = water(val, main, sub, non);
                if(visited.count(nt) == 0){
                    visited.insert(nt);
                    q.emplace(nt);
                }
            }
        }while(next_permutation(per.begin(), per.end()));
    }

}
int main(void){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> A >> B >> C;
    mx = {A,B,C};
    
    bfs();
    for(int a: ans){
        cout << a << ' ';
    }
    cout << '\n';
    return 0;
}
