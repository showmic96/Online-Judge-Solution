// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[105];
int n;

ll f(int i)
{
    if(i==n)return 1;
    if(i>n)return 0;
    if(dp[i]!=-1)return dp[i];

    ll value = 0;
    value+=f(i+2);
    value+=f(i+3);

    return dp[i] = value;
}
int main(void)
{
    while(scanf("%d",&n)==1){

        memset(dp , -1 , sizeof(dp));
        n++;
        printf("%lld\n",f(0)+f(1));
    }
    return 0;
}
