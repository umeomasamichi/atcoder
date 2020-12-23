#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int q;
string x, y;
vector<vector<int>> dp(1010, vector<int>(1010, 0));

int main(){
    cin >> q;
    rep(i, q){
        cin >> x >> y;
        rep(i, 1010)rep(j, 1010) dp[i][j] = 0;
        
        for(int j=1;j<=y.size();j++){
            dp[j] = dp[j-1];
            for(int k=1;k<=x.size();k++){
                dp[j][k] = max(dp[j][k], dp[j][k-1]);
                if(y[j-1]==x[k-1]) dp[j][k] = dp[j-1][k-1] + 1;
            }
        }
        
        cout << dp[y.size()][x.size()] << endl;
    }

    return 0;
}