/*
백준 8772번
Szyfr Cezara
BRONZ 2
싸이퍼 암호
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
      int a;
      string s;
      string c;
      cin >> a >> s >> c;
      int diff = (c[0] - s[0] + 26) % 26;
      for (int i = 1; i < s.length(); i++) {
          int num = s[i] + diff;
          if(num > 122){
              num %= 122;
              num += 96;
          }
          c.push_back(char(num));
      }
      cout << c << '\n';
    }
    return 0;
}