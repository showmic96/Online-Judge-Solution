// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[20][(1<<20)+5];
int n , ar[20][20];

int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

ll f(int i , int mask)
{
    if(i==n){

        return 1;
    }

    if(dp[i][mask]!=-1)return dp[i][mask];

    ll value = 0;

    for(int i1=0;i1<n;i1++){

        if(ar[i][i1]==1){

            if(Check(mask , i1)==false){

                value+=f(i+1 , Set(mask , i1));
            }
        }
    }

    return dp[i][mask] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));

        scanf("%d",&n);
        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                scanf("%d",&ar[i][j]);
            }
        }

        printf("%lld\n",f(0 , 0));
    }
    return 0;
}
