// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[205];
ll dp[205] , n;
ll MX = INT_MAX;

ll f(int i)
{
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];

    ll value = 0 , now = 0;
    for(int j=i;j<n;j++){

        now*=10;
        now+=ar[j]-'0';
        if(now>MX)break;
        value = max(value , f(j+1)+now);
    }

    return dp[i] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%s",&ar);
        n = strlen(ar);
        memset(dp , -1 , sizeof(dp));
        printf("%lld\n",f(0));
    }

    return 0;
}
