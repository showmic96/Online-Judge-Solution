// In the name of Allah the Lord of the Worlds.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 2e5+9;
ll ar[MAX] , br[MAX] , c , n , dp[MAX][2];

ll f(int now , int e = 0)
{
    if(now==0)return 0;
    if(dp[now][e]!=-1)return dp[now][e];
    ll value = 1e18;
    if(e==0){
        value = min(value , f(now-1 , e)+ar[now]);
        value = min(value , f(now-1 , 1)+br[now]+c);
    }
    else{
        value = min(value , f(now-1 , 0)+ar[now]);
        value = min(value , f(now-1 , 1)+br[now]);
    }
    return dp[now][e] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> c;
    for(int i=1;i<n;i++){
        cin >> ar[i];
    }
    for(int i=1;i<n;i++){
        cin >> br[i];
    }
    memset(dp , -1 , sizeof(dp));
    for(int i=0;i<n;i++){
        if(i>0)cout << " ";
        cout << f(i);
    }
    cout << endl;

    return 0;
}
