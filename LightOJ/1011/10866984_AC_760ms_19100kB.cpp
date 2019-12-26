// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

ll w[17][17];
ll dp[17][(1<<17)+9];

bool Check(int n , int pos){

    return n&(1<<pos);
}

int Set(int n , int pos){

    return n|(1<<pos);
}

ll f(int i , int mask)
{
    if(i==n)return 0;
    if(dp[i][mask]!=-1)return dp[i][mask];

    ll mi = 0;

    for(int j=0;j<n;j++){

        if(Check(mask , j)==0){

            ll temp = w[i][j] + f(i+1 , Set(mask , j));

            mi = max(mi , temp);
        }
    }

    return dp[i][mask] = mi;
}

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        cin >> n;
        memset(dp , -1 , sizeof(dp));
        for(int j=0;j<n;j++){

            for(int k=0;k<n;k++){

                cin >> w[j][k];
            }
        }

        printf("Case %d: %lld\n",i+1 , f(0 , 0));
    }

    return 0;
}
