// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1234 , MOD = 10056;
int ncr[MAX][MAX];
int dp[MAX] , n;


int nCr(int n , int r)
{
    if(r==1)return n;
    if(n==r)return 1;

    if(ncr[n][r]!=-1)return ncr[n][r];

    return ncr[n][r] = (nCr(n-1 , r) + nCr(n-1 , r-1))%MOD;
}

int f(int i)
{
    if(i==0)return 1;

    if(dp[i]!=-1)return dp[i];

    int value = 0;

    for(int j=1;j<=i;j++){

        value+= (nCr(i , j)*f(i-j));
        value%=MOD;
    }

    return dp[i] = value;
}

int main(void)
{
    memset(ncr , -1 , sizeof(ncr));
    memset(dp , -1 , sizeof(dp));
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){


        int n;
        scanf("%d",&n);

        printf("Case %d: %d\n",i+1 , f(n));

    }
    return 0;
}
