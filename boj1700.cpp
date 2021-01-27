/*
백준 1700번
멀티탭 스케줄링
GOLD 2
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N,M;
vector<queue<int>> elec;
vector<int> schedule;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    elec.resize(M+1);
    schedule.resize(M);
    
    for(int i = 0 ;i < M; ++i){
        cin >> schedule[i];
        elec[schedule[i]].emplace(i);
    }
    set<int> multi;
    int ans = 0;
    for(int i = 0 ;i < M; ++i){
        
        if(multi.find(schedule[i]) == multi.end() && multi.size() >= N){
            int bye = 0, idx = 0;
            for(auto mul : multi){
                if(elec[mul].empty()){
                    bye = mul;
                    break;
                }
                else if(elec[mul].front() > idx){
                    idx = elec[mul].front();
                    bye = mul;
                }
            }
            multi.erase(multi.find(bye));
            ans++;
        }
        
        multi.insert(schedule[i]);
        elec[schedule[i]].pop();
    }
    cout << ans << '\n';
    
    return 0;
}
