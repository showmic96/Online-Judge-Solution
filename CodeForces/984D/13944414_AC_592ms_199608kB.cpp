// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int dp[5005][5005] , dp2[5005][5005];
int ar[5005];

int f(int l , int r)
{
    if(l>r)return 0;
    if(l==r)return ar[l];
    if(dp[l][r]!=-1)return dp[l][r];
    return dp[l][r] = f(l+1 , r) ^ f(l , r-1);
}

int f2(int l ,int r)
{
    if(l>r)return 0;
    if(l==r)return ar[l];
    if(dp2[l][r]!=-1)return dp2[l][r];

    return dp2[l][r] = max(f(l , r) , max(f2(l+1 , r) , f2(l , r-1)));
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));
    memset(dp2 , -1 , sizeof(dp));

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)scanf("%d",&ar[i]);

    int q;
    scanf("%d",&q);

    while(q--){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);

        printf("%d\n",f2(in1 , in2));
    }

    return 0;
}
