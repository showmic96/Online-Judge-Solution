// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e3 + 9;

ll dp[MAX+9][MAX+9][4];
char ar[MAX+9];

int n;

ll f(int i , int k , int now)
{

    if(i>=n)return 1e9;

    if(i==n-1){

        if(now==0)return 0;
        return 2;
    }


    if(dp[i][k][now]!=-1)return dp[i][k][now];

    dp[i][k][now] = 1e9;

    ll value = 1e9;


    if(ar[i+1]!='#'&&now==0){
        value = min(value , f(i+1 , k , 0)+1);
    }

    if(now==0&&k>0){

        value = min(value , f(i+1 , k-1 , 0)+1);

    }

    if(now==0){

        value = min(value , f(i+1 , k , 1)+4);
    }

    if(now==1){

        if(ar[i]!='#')value = min(value , f(i , k , 0)+2);
        value = min(value , f(i+1 ,  k , 1)+2);
    }

    return dp[i][k][now] = value;
}

int main(void)
{
    int t , k;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));
        scanf("%d %d",&n ,&k);
        scanf("%s",&ar);

        printf("%lld\n",f(0 , k , 0));
    }
    return 0;
}
