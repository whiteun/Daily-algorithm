/*
백준 2294번
동전 2
SILVER 2

DP
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 10001
using namespace std;

int N,K;
vector<int> coin;
vector<int> dp; //X원을 만들 수 있는 최소 동전의 수

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K;
    coin.resize(N);
    dp.resize(K+1, MAX_N);
    
    for(int i = 0 ;i < N; ++i){
        cin >> coin[i];
        if(coin[i] <= K) dp[coin[i]] = 1;
    }
    
    //bottom-up
    for(int i = 1; i <= K; ++i){
        for(int c : coin){
            if(i-c <= 0) continue;
            dp[i] = min(dp[i], dp[i-c]+1);
        }
    }
    
    int ans = dp[K];
    if(ans >= MAX_N){
        cout << "-1\n";
        return 0;
    }
    cout << ans << '\n';
    return 0;
}
