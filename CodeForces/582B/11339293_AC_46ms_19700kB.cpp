// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v1 , v2;
ll n , t , n_temp;

ll dp[8005][305];

ll f(int i , int last)
{
    if(i==n_temp)return 0;
    if(dp[i][last]!=-1)return dp[i][last];

    ll value = 0;

    value=f(i+1 , last);

    if(v2[i]>=last){

        value = max(value , f(i+1 , v2[i])+1);
    }

    return dp[i][last] = value;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));

    n , t;
    scanf("%lld %lld",&n ,&t);

    n_temp = n;

    while(n_temp<=7000){

        if(n_temp>=n*t)break;
        n_temp+=n;
    }

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v1.push_back(in);
    }

    for(int i=0;i<n_temp;i++){

        v2.push_back(v1[i%n]);
    }

    ll ans = f(0 , 0);

    if(n_temp==n*t){

        printf("%lld\n",ans);
    }
    else{

        for(int i=0;i<n;i++){

            v2.push_back(v1[i]);
        }

        n_temp+=n;

        memset(dp , -1 , sizeof(dp));

        ll ans2 = f(0 , 0);
        n_temp-=n;

        ll temp = (ans2-ans)*(t-(n_temp/n));

        printf("%lld\n",ans+temp);
    }

    return 0;
}
