// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , c , dp[200005][2];
vector<ll>v;

ll f(int i , int state)
{
    if(i==n){

        return 0;
    }
    if(dp[i][state]!=-1)return dp[i][state];

    ll value = f(i+1, state);

    if(state==0){

        value = max(value , f(i+1 , 1)-v[i]-c);
    }
    if(state==1){

        value = max(value , f(i+1 , 0)+v[i]);
    }
    return dp[i][state] = value;
}

int main(void)
{
    while(scanf("%lld %lld",&n , &c)==2){

        v.clear();

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }
        memset(dp , -1 , sizeof(dp));

        printf("%lld\n",f(0 , 0));
    }

    return 0;
}
