/*
백준 12764번
싸지방에 간 준하
GOLD 4
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int cnt = 0;
vector<pair<int, int>> sold;
priority_queue<pair<int, int>> jobq; //종료시간, 번호
priority_queue<int> waitq; //번호
vector<int> ans;

int main(void)
{
    int N;
    cin >> N;

    while(N--){
        int st, en;
        cin >> st >> en;
        sold.emplace_back(st, en);
    }
    sort(sold.begin(), sold.end());

    for(auto[st, en] : sold){
        while(!jobq.empty() && -jobq.top().first <= st){
            int top = jobq.top().second;
            jobq.pop();
            waitq.emplace(-top);
        }
        if(waitq.empty()){
            ans.emplace_back(0);
            waitq.emplace(-cnt);
            cnt++;
        }
        int num = -waitq.top();
        waitq.pop();
        ans[num]++;
        jobq.emplace(-en, num);
    }
    cout << cnt << '\n';
    for(int a : ans){
        cout << a << ' ';
    }
    cout << '\n';
    return 0;
}