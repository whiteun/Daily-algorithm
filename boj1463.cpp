/*
 백준 1463번
 1로 만들기
 SILVER 3
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 1e9

using namespace std;

typedef long long ll;

vector<int> dp;

int topDown(int n){
    if (dp[n] < INF || n == 1) return dp[n];
    dp[n] = min(topDown(n-1)+1, dp[n]);
    
    if(n%3 == 0){
        dp[n] = min(topDown(n/3)+1, dp[n]);
    }
    if(n%2 == 0){
        dp[n] = min(topDown(n/2)+1, dp[n]);
    }
    return dp[n];
}
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
   
    dp.resize(N+1, INF);
    
    dp[0] = 1;
    dp[1] = 0;
    cout << topDown(N) << '\n';
    
    return 0;
}

