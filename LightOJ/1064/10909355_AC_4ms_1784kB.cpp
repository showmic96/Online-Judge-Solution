// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[25][250][2];
ll n , x;

ll f(int i , int sum , int s)
{
    if(sum>=x){

        sum = 0;
        s = 1;
    }

    if(i==n){

        if(sum>=x)return 1;
        if(s==1)return 1;
        return 0;
    }

    if(dp[i][sum][s]!=-1)return dp[i][sum][s];

    ll value = 0;

    for(int j=1;j<=6;j++){

        value+=f(i+1 , sum+j , s);
    }

    return dp[i][sum][s] = value;
}

int main(void)
{

    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));

        scanf("%lld %lld",&n ,&x);

        ll ans = f(0 , 0 , 0);

        ll dem = 1;

        for(int i=0;i<n;i++){

            dem*=6;

            ll temp = __gcd(ans , dem);

            ans/=temp;
            dem/=temp;
        }

        if(ans!=dem&&ans!=0)printf("Case %d: %lld/%lld\n",++c , ans , dem);
        else printf("Case %d: %lld\n",++c , ans);
    }

    return 0;
}
