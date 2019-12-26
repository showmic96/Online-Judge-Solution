// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

ll w[17][17];
ll dp[17][(1<<17)+9];

bool check(int N , int POS){

    return N&(1<<POS);
}

int Set(int N , int POS){

    return N|(1<<POS);
}

ll f(int i , int mask)
{
    if(i==n)return 0;
    if(dp[i][mask]!=-1)return dp[i][mask];

    ll mi = 0;

    for(int j=0;j<n;j++){

        if(check(mask , j)==0){

            ll temp = w[i][j] + f(i+1 , Set(mask , j));

            mi = max(mi , temp);
        }
    }

    return dp[i][mask] = mi;
}

int main(void)
{
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
