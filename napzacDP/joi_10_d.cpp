#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<vector<ll>> dp(n, vector<ll>(21, 0));
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    dp[0][a[0]] = 1;
    for(int i=1;i<n-1;i++){
        rep(j, 21){
            if(dp[i-1][j]!=0){
                if(j+a[i]<=20) dp[i][j+a[i]] += dp[i-1][j];
                if(j-a[i]>=0) dp[i][j-a[i]] += dp[i-1][j];
            }
        }
    }


    cout << dp[n-2][a[n-1]] << endl;
    
    return 0;
}