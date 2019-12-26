// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n , k;

ll dp[20][2];

ll f(int i , int pre)
{
    if(i==n){

        return 1;
    }

    if(dp[i][pre]!=-1)return dp[i][pre];

    ll value = 0;

    if(pre==0){

        value+=f(i+1 , 1);
        value+=(ll)(k-1)*f(i+1 , 0);
    }
    else{

        value+=(ll)(k-1)*f(i+1 , 0);
    }

    return dp[i][pre] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    memset(dp , -1 , sizeof(dp));

    ll ans = (ll)(k-1LL)*f(1 , 0);
    cout << ans << endl;

    return 0;
}
