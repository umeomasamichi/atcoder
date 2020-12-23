#include<bits/stdc++.h>
using namespace std;

int n, q;
vector<int> s, t;

int main(){
    //input
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        s.push_back(tmp);
    }
    cin >> q;
    for(int i=0;i<q;i++){
        int tmp;
        cin >> tmp;
        t.push_back(tmp);
    }

    //syori
    int ans = 0;

    for(int i=0;i<q;i++){
        int target = t[i];
        for(int j=0;j<n;j++){
            if(s[j]==target){
                ans++; break;
            }
        }
    }

    //output
    cout << ans << endl;

    return 0;
}