// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll w[15][15];
ll dp[(1<<15)+9];

int Set(int n , int pos)
{
    return (n|(1<<pos));
}

int reSet(int n , int pos)
{
    return (n&~(1<<pos));
}

bool Check(int n , int pos)
{
    return (n&(1<<pos));
}

ll f(int mask)
{
    if(mask==(1<<n)-1)return 0;
    if(dp[mask]!=-1)return dp[mask];

    ll mi = (1<<28);

    for(int i=0;i<n;i++){

        if(Check(mask , i)==0){

            ll price = w[i][i];

            for(int j=0;j<n;j++){

                if(i!=j&&Check(mask , j)!=0){

                    price+=w[i][j];
                }
            }
            ll ret = price + f(Set(mask , i));
            mi = min(mi , ret);
        }
    }

    return dp[mask] = mi;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i=0;i<t;i++){

        memset(dp  , -1 , sizeof(dp));
        cin >> n;

        for(int j=0;j<n;j++){

            for(int k=0;k<n;k++){

                cin >> w[j][k];
            }
        }

        printf("Case %d: %lld\n",i+1,f(0));
    }
}
