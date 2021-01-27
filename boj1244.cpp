/*
백준 1244번
스위치 켜고 끄기
SILVER 4
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,M;
vector<int> sw;

void man(int n){
    for(int i = n; i <= N; i+=n){
        sw[i] = !sw[i];
    }
}
void woman(int n){
    int l = n, r = n;
    sw[n] = !sw[n];
    while(l >= 1 && r <= N && sw[l] == sw[r]){
        sw[l] = !sw[l];
        sw[r] = !sw[r];
        l--,r++;
    }
}

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    sw.resize(N+1);
    for(int i = 1 ;i <= N; ++i){
        int a;
        cin >> a;
        sw[i] = a;
    }
    cin >> M;
    while(M--){
        int wm, num;
        cin >> wm >> num;
        if(wm == 1) man(num);
        else woman(num);
    }
    
    for(int i = 1; i <= N; ++i){
        cout << sw[i] << ' ';
        if(i%20 == 0) cout << '\n';
    }
    return 0;
}
