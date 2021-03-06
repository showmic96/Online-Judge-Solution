// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[105][10005];

int v1 , v2 , t , d;

ll f(int i , int v)
{
    if(i==t-1){
        if(v==v2)return v;
        return -1234567;
    }

    if(dp[i][v]!=-1)return dp[i][v];

    ll value = -1234567;

    for(int j=0;j<=d;j++){

        value = max(value , f(i+1 , v+j)+v);
        if(v-j>=v2)value = max(value , f(i+1 , v-j)+v);
    }

    return dp[i][v] = value;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));
    cin >> v1 >> v2 >> t >> d;

    cout << max((ll)0, f(0 , v1)) << endl;

    return 0;
}
