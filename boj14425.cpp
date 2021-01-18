/*
백준 14425번
문자열 집합
*/
#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    set<string> sset;
    int N, M;
    cin >> N >> M;
    while(N--){
        string temp;
        cin >> temp;
        sset.insert(temp);
    }
    int ans = 0;
    while(M--){
        string temp;
        cin >> temp;
        if(sset.count(temp) > 0) 
            ans++;
    }
    cout << ans << '\n';
    return 0;
}