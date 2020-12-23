#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//https://suzulang.com/c-stdvector-resize%E3%81%A8reserve%E3%81%AE%E9%81%95%E3%81%84-%E5%8A%A0%E7%AD%86%E4%B8%AD%EF%BC%9F/

int n, q;
vector<int> s, t;

int main(){
    cin >> n;
    s.resize(n);
    rep(i, n) cin >> s[i];
    cin >> q;
    t.resize(q);
    rep(i, q) cin >> t[i];

    //syori
    int ans = 0;
    rep(i, q){
        if(binary_search(s.begin(), s.end(), t[i])) ans++;
    }


    //output
    cout << ans << endl;

    return 0;
}