/*
백준 1992번
쿼드 트리
SILVER 1
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int N;
char board[65][65];

string recursion(int sz, int rst, int ren, int cst, int cen){
    char ret[2] = {board[rst][cst]};
    if(sz <= 1)
        return string(ret);
    
    for(int r = rst; r < ren; ++r){
        for(int c = cst; c < cen; ++c){
            if(board[r][c] != ret[0]){
                ret[0] = 'X';
                break;
            }
        }
    }
    if(ret[0] != 'X') return string(ret);
    
    return "("
        +recursion(sz/2, rst, rst+sz/2, cst, cst+sz/2)
        +recursion(sz/2, rst, rst+sz/2, cst+sz/2, cen)
        +recursion(sz/2, rst+sz/2, ren, cst, cst+sz/2)
        +recursion(sz/2, rst+sz/2, ren, cst+sz/2, cen)
        +")";
}

int main(void)
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for(int i = 0 ;i < N; ++i){
        string S;
        cin >> S;
        for(int j = 0 ; j < N; ++j){
            board[i][j] = S[j];
        }
    }
    string ans = recursion(N, 0, N, 0, N);
    cout << ans << '\n';
    return 0;
}