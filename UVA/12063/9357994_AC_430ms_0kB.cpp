// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[65][33][33][112];

ll n , k;

ll f(int i , int o , int z , int sum)
{
    if(k==0)return 0;

    if(i==n){

        if(o==z&&sum==0){

            return 1;
        }

        return 0;
    }

    if(dp[i][o][z][sum]!=-1)return dp[i][o][z][sum];

    ll value = 0;

    if(i==0){

        value+=f(i+1 , o+1 , z , ((sum<<1)%k + 1) %k);
    }

    else{

        value+=f(i+1 , o , z+1 , (sum<<1)%k);
        value+=f(i+1 , o+1 , z , ((sum<<1)%k + 1) %k);
    }

    return dp[i][o][z][sum] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        memset(dp , -1 ,sizeof(dp));

        scanf("%lld %lld",&n , &k);

        ll ans = f(0 , 0 , 0 , 0);

        printf("Case %d: %lld\n",++c , ans);
    }
    return 0;
}