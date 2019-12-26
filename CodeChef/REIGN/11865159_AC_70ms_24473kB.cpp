// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;

ll dp[MAX+9][6];
vector<ll>v;
int n , k;

ll f(int i , int now)
{
    if(i>n)return -1e18;
    if(i==n){

        if(now>=3)return 0;
        return -1e18;
    }

    if(dp[i][now]!=-1)return dp[i][now];

    ll value = -1e18;

    if(now==0){

        value = max(value , f(i+1 , now));
        value = max(value , f(i+1 , now+1)+v[i]);
    }

    else if(now==1){

        value = max(value , f(i+1 , now)+v[i]);
        value = max(value , f(i+k , now+1));
    }

    else if(now==2){

        value = max(value , f(i+1 , now));
        value = max(value , f(i+1 , now+1)+v[i]);
    }

    else if(now==3){

        value = max(value , f(i+1 , now)+v[i]);
        value = max(value , f(i+1 , now+1));
    }

    else value = max(value , f(i+1 , now));

    return dp[i][now] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));

        v.clear();
        scanf("%d %d",&n,&k);

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        printf("%lld\n",f(0 , 0));

    }
    return 0;
}
