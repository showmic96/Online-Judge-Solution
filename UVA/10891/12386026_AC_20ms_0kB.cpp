// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[105][105];
vector<ll>v;

ll f(int l , int r)
{
    if(l>r)return 0;
    //if(l==r)return v[l];
    if(dp[l][r]!=-1)return dp[l][r];
    dp[l][r] = 0;

    ll value = -1e14;
    ll sum = 0;

    for(int i=l;i<=r;i++){

        sum+=v[i];
        value = max(value , sum-f(i+1 , r));
    }

    sum = 0;

    for(int i=r;i>=l;i--){

        sum+=v[i];
        value = max(value , sum-f(l , i-1));
    }

    return dp[l][r] = value;
}

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        if(!n)break;
        memset(dp , -1 , sizeof(dp));
        v.clear();

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        printf("%lld\n",f(0 , n-1));
    }
    return 0;
}
