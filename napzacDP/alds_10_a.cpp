#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int n;

int main(){
    vector<ll> fib(50);
    fib[0] = 1;
    fib[1] = 1;
    cin >> n;
    for(int i=2;i<=n;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    cout << fib[n] << endl;

    return 0;
}
