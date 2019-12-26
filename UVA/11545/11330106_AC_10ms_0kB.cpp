// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[1000+5][20][24];

int si;
string ar;

ll f(int i, int l , int d)
{
    if(dp[i][l][d]!=-1)return dp[i][l][d];

    if(l>16)return 1e12;

    if(ar[i]=='D'){
        return 0;
    }

    if(ar[i]=='*'&&(d<=6||d>=18))return 1e12;

    ll value = 1e12;

    value = min(value , f(i+1 , l+1 , (d+1)%24)+1);

    value = min(value , f(i+1, 1 ,(d+9)%24)+9);

    return dp[i][l][d] = value;
}

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int t , c = 0;
    cin >> t;

    while(t--){

        memset(dp , -1 , sizeof(dp));

        cin >> ar;

        si = ar.size();

        ll ans = f(0 , 0 , 6);

        if(ans>=1e12)ans = -1;

        printf("Case #%d: %lld\n",++c , ans);
    }

    return 0;
}
