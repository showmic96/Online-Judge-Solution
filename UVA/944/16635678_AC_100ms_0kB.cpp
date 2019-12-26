// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[100005];

int f(int n)
{
    if(n==1)return 1;
    if(dp[n]!=-1)return dp[n];
    dp[n] = 1e9;

    int now = 0 , temp = n;
    while(temp){

        int t = temp%10;
        now+=t*t;
        temp/=10;
    }
    return dp[n] = f(now)+1;
}

int main(void)
{
    int n , m;
    bool blank = false;

    memset(dp , -1 , sizeof(dp));

    while(scanf("%d %d",&n , &m)==2){

        if(blank==true)printf("\n");
        blank = true;

        for(int i=n;i<=m;i++){

            int ans = f(i);
            if(ans<1e9)printf("%d %d\n",i , ans);
        }
    }
    return 0;
}
