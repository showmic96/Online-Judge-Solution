// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[105][10005];

vector<ll>cost;
int n;
int total;
int pre;

ll f(int i , int value)
{
    if(value>=total){

        return value;
    }

    if(i==n)return 1e9;

    if(dp[i][value]!=-1)return dp[i][value];

    ll v = 1e9;

    v = min(v , f(i+1 , value));
    v = min(f(i+1 , value + cost[i]) , v);

    return dp[i][value] = v;
}

ll f2(int i , int value)
{
    if(value==total){

        return 0;
    }
    
    if(value>total)return 1e9;

    if(i==n)return 1e9;

    if(dp[i][value]!=-1)return dp[i][value];

    ll v = 1e9;

    v = min(v , f2(i+1 , value));
    v = min(f2(i+1 , value + cost[i])+1 , v);

    return dp[i][value] = v;
}


int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d",&total , &n);
        cost.clear();
        memset(dp , -1 , sizeof(dp));

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            cost.push_back(in);
        }

        ll ans = f(0 , 0);
        total = ans;

        memset(dp , -1 , sizeof(dp));

        ll ans2 = f2(0 , 0);

        printf("%lld %lld\n",ans , ans2);
    }
    return 0;
}
