#include<iostream>
#include<cmath>
using namespace std;

long long x[30], y[30], n, m, sum=1, mod=1000000007;

int pow_kai(int a, int n){//aのn乗を計算します。
  int x = 1;
  while(n > 0){//全てのbitが捨てられるまで。
    if(n&1){//1番右のbitが1のとき。
      x = x*a;
    }
    a = a*a;
    n >>= 1;//bit全体を右に1つシフトして一番右を捨てる。
  }
  return x;
}


int main(){

    cin >> m >> n;

    //mを2進数に変換(x[i]に格納)
    for(int i=0;i<30;i++){
        x[i] = (n / (int)pow(2, i)) % 2;
    }

    y[0] = m;

    //y[i]には(y^i)%mod を格納
    for(int i=1;i<30;i++){
        y[i] = (y[i-1]*y[i-1]) % mod;
    }

    //y^i
    for(int i=0;i<30;i++){
        if(x[i]==1){
            sum *= y[i];
            sum %= mod;
        }
    }

    cout << sum << endl;

    return 0;
}