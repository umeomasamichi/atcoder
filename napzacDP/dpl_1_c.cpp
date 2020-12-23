#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

vector<vector<int>> dp;

int main(){
    //input
    int n, w;
    cin >> n >> w;
    dp.resize(n+1, vector<int>(w+1, -1));
    vector<pair<int, int>>  goods(n+1);
    for(int i=1;i<n+1;i++){
        cin >> goods[i].first;
        cin >> goods[i].second;
    }

    //syori
    rep(i, n+1) dp[i][0] = 0;
    for(int i=1;i<=n;i++){
        rep(j, w+1){
            if(dp[i-1][j]!=-1){
                dp[i][j] = max(dp[i-1][j], dp[i][j]);
            }
            if(dp[i][j]!=-1){
                if(j+goods[i].second<=w) dp[i][j+goods[i].second] = dp[i][j] + goods[i].first;
            }
        }
    }

    //output
    int ans = 0;
    rep(i, w+1) ans = max(ans, dp[n][i]);
    cout << ans << endl;

    return 0;
}