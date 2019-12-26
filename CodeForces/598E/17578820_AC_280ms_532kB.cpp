// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[35][35][55];

ll f(int n , int m , int k)
{
    if(k==0)return 0;
    if(n*m==k)return 0;
    if(k>n*m)return 1e9;
    if(dp[n][m][k]!=-1)return dp[n][m][k];

    ll value = 1e18;

    for(int i=1;i<n;i++){

        for(int j=0;j<k;j++){

            value = min(value , m*m+f(i , m , j)+f(n-i , m , k-j));
        }
    }

    for(int i=1;i<m;i++){

        for(int j=0;j<k;j++){

            value = min(value , n*n+f(n , i , j)+f(n , m-i , k-j));
        }
    }

    return dp[n][m][k] = value;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));

    int t;
    scanf("%d",&t);

    while(t--){

        int n , m , k;
        scanf("%d %d %d",&n , &m , &k);
        printf("%lld\n",f(n , m , k));
    }
    return 0;
}
