/*
백준 11478번
서로 다른 부분 문자열의 개수 
*/

#include <iostream>
#include <set>
using namespace std;

set<string> sset;

int main(void)
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);    
    string s;
    cin >> s;

    int len = s.length();

    while(len > 0){
        for(int i = 0 ;i < (int)s.length()-len+1; ++i){
            string temp = s.substr(i,len);
            sset.insert(temp);
        }
        len--;
    }

    cout << sset.size() << '\n';
    return 0;
}