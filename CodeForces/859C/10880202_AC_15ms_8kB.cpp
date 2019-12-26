// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v;
int n;
ll dp[55][3];

ll f(int i , int pre)
{
    if(i==n)return 0;

    if(dp[i][pre]!=-1)return dp[i][pre];

    ll value = 0;

    if(pre==0){

        value = f(i+1 , 0);
        value = max(value , f(i+1, 1)+v[i]);

        return dp[i][pre] = value;
    }
    else{

        value = f(i+1 , 1) + v[i];
        value = min(f(i+1 , 0), value);

        return dp[i][pre] = value;
    }
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));
    scanf("%d",&n);

    ll sum = 0;

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
        sum+=in;
    }

    ll ans = f(0 , 0);

    printf("%lld %lld\n",sum - ans , ans);

    return 0;
}
