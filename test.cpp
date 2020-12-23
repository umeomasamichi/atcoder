#include <iostream>
#include <cmath>
using namespace std;

int m, n, x[30], y[30], sum = 1;
int mod = 1000000007;

int main()
{
    cin >> m >> n;
    for(int i=0;i<30;i++){
        x[i] = (n/(int)pow(2, i)) % mod;
    }

    y[0] = m;

    for(int i=0;i<30;i++){
        y[i] = y[i-1]*y[i-1] % mod;
    }

    for(int i=0;i<30;i++){
        if(x[i]==1) {
            sum*=y[i];
            sum %= mod;
        }
    }

    cout << sum << endl;

    return 0 ;
} 