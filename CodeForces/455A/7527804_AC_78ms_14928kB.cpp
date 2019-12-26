// In the name of Allah the most Merciful

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[1000000+10];
map<ll,ll>maping;

ll f(ll a)
{
    if(dp[a]!=-1)return dp[a];
    if(a==1)return maping[1];
    if(a==0)return 0;

    return dp[a] = max(f(a-1) , f(a-2)+maping[a]*a);
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));
    ll a , in , hi=0 ;
    scanf("%lld",&a);

    for(int i=0;i<a;i++){

        scanf("%lld",&in);
        maping[in]++;

        if(in>hi)hi = in;

    }
    cout << f(hi) << endl;

    return 0;
}
