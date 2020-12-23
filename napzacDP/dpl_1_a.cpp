#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
#define INF 1000000

int n, m;
vector<int> c;
vector<vector<int>> dp;

int main(){
    cin >> n >> m;
    c.resize(m);
    rep(i, m) cin >> c[i];
    sort(c.begin(), c.end(), greater<int>());
    dp.resize(m+1, vector<int>(n+1, INF));
    rep(i, m+1) dp[i][0] = 0;

    //syori
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            //上と比較して，少ない回数のほうを採用
            if(dp[i-1][j]!=INF) dp[i][j] = min(dp[i-1][j], dp[i][j]);
            //現在の場所に到達できて，さらにそのコインを使ったとき，n円を超えていなければ更新
            if(dp[i][j]!=INF){
                if(j+c[i-1]<=n) dp[i][j+c[i-1]] = dp[i][j]+1;
            }
        }
    }

    //output
    cout << dp[m][n] << endl;

    return 0;
}