/*
백준 1600번
말이 되고픈 원숭이
GOLD 5
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
int K, W, H;
int board[201][201];
bool visit[201][201][31];
int dr[] = {0,0,1,-1};
int dc[] = {-1,1,0,0};
int hdr[] = {-1,-2,-2,-1, 1, 2,2,1};
int hdc[] = {-2,-1, 1, 2,-2,-1,1,2};
bool OOB(int r, int c){
    if(r < 0 || c < 0 || r >= H || c >= W) return true;
    return false;
}
int bfs(){
    queue<tuple<int,int, int, int> > q; //R(좌표), C(좌표), 몇회, 말 능력 사용수
    q.emplace(0,0,0,0);
    visit[0][0][0] = true;
    while(!q.empty()){
        auto [r, c, t, k] = q.front(); q.pop();
        if(r >= H-1 && c >= W-1){
            return t;//최소 횟수 리턴
        }
        int nr, nc;
        if(k < K){
            for(int i = 0 ;i < 8; ++i){
                nr = r+hdr[i];
                nc = c+hdc[i];
                if(OOB(nr, nc) || board[nr][nc] || visit[nr][nc][k+1]) continue;
                q.emplace(nr, nc, t+1, k+1);
                visit[nr][nc][k+1] = true;
            }
        }
        for(int i = 0 ;i < 4; ++i){
            nr = r+dr[i];
            nc = c+dc[i];
            if(OOB(nr, nc) || board[nr][nc] || visit[nr][nc][k]) continue;
            q.emplace(nr, nc, t+1, k);
            visit[nr][nc][k] = true;
        }
    }
    return -1;
}
int main(void){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> K >> W >> H;
    for(int i = 0 ;i < H; ++i){
        for(int j = 0 ; j < W; ++j){
            cin >> board[i][j];
        }
    }
    cout << bfs() << '\n';
    return 0;
}
