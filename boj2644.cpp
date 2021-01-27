/*
백준 2644번
촌수 계산
SILVER 2
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N,M;
vector<vector<int>> adj;
vector<bool> visit;

int bfs(int x, int y){
    queue<pair<int, int>> q;
    q.emplace(x, 0);
    visit[x] = 1;
    while(!q.empty()){
        auto [now, dist] = q.front();
        q.pop();
        if(now == y) return dist;
        for( auto nxt : adj[now]){
            if(!visit[nxt]) {
                q.emplace(nxt, dist+1);
                visit[nxt] = 1;
            }
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    adj.resize(N+1);
    visit.resize(N+1);
    int x, y;
    cin >> x >> y;
    
    cin >> M;
    while(M--){
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    cout << bfs(x,y) << '\n';
    
    return 0;
}
