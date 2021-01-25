/*
백준 1111번
IQ Test
GOLD 2
*/
#include <iostream>
#include <vector>
using namespace std;

int N;
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    vector<int> v(N);
    for(int i = 0 ; i < N; ++i){
        cin >> v[i];
    }
    if (N < 3){
        if( N == 2 && v[0] == v[1]) cout << v[0] << '\n';
        else cout << "A\n";
    }
    else{
        int a = v[0]-v[1] != 0 ? (v[1]-v[2])/(v[0]-v[1]) : 1;
        int b = v[1] - a*v[0];
        
        if (a * v[0] + b != v[1]){
            cout << "B\n";
        }
        else{
            int i;
            for(i = 2; i < N; ++i){
                if( a* v[i-1] +b != v[i]){
                    cout << "B\n";
                    break;
                }
            }
            if (i >= N)
                cout << v.back()*a + b << '\n';
        }
        
    }
    return 0;
}
