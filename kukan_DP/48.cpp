#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n, a[1000], dp[1000][1000];
//dp[i][j]は，i~jまでの区間で考えたとき，何個取り除けるかを表す

//debug用
void matrix(int ix, int jx){
    cout << ix << ", " << jx << endl;
    int x=15;
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(i==ix && j==jx) cout << dp[i][j] << "o";
            else cout << dp[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
for(見る区間を徐々に大きく){
    for(前から順番に見ていく){
        ・左の塊と右の塊がそれぞれで消える場合
        ・真ん中が消えて，左端と右端が消える場合
        この2つを考えてdpを更新
    }
}


*/


int main(){
    while(true){
        cin >> n;
        if(n==0)break;
        //初期化
        for(int i=0;i<1000;i++){
            for(int j=0;j<1000;j++){
                dp[i][j]=0;
            }
        }
        //入力
        for(int i=0;i<n;i++)cin >> a[i];

        //隣り合った2つが取り除けるかどうかいったん全部見る
        for(int i=0;i<n-1;i++){
            if(abs(a[i]-a[i+1])<=1){
                dp[i][i+1]=2;
            }
        }
        
        //iは長さ-1　jは開始位置
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++){
                
                int a1 = j, a3 = i+j;
                //a1: 注目する区間の最前の位置
                //a3: 最後尾の位置
                
                //範囲を超えてないか確認
                if(a3>=n)continue;
                
                
                //a2を(a1+1)~a3の値として，
                //a1~(a2-1), a2~a3の組み合わせを考える
                //こっちは，a~(a2-1)のかたまりと，a2~a3のかたまりの間で消滅がおこらない
                for(int k = a1+1;k<=a3;k++){
                    int a2=k;
                    dp[a1][a3]=max(dp[a1][a3], dp[a1][a2-1]+dp[a2][a3]);
                }
                
                //こっちは，端同士で消滅が起きる
                //a1~a3までがすべて消滅して，a1の左とa3の右が存在し，その２つの差が1以下の場合に消滅が起こる
                if(dp[a1][a3]==i+1 && a1>0 && a3<n-1 && abs(a[a1-1]-a[a3+1])<=1){
                    dp[a1-1][a3+1] = dp[a1][a3] + 2;
                }

                matrix(a1, a3);
            }
        }

        //出力（0~n-1までの区間で取り除ける最大の数）
        cout << dp[0][n-1] << endl;
    }

    return 0;
}