// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bitset<1000005>bs;
vector<ll>primes;
ll dp[25][1005] , n;

ll p(ll temp , ll lim)
{
    ll now = 1;
    for(int i=1;i<=lim;i++)now*=temp;
    return now;
}

ll f(int now , int rem)
{
    if(now==12){

        if(rem==1)return 1LL;
        return -2;
    }
    if(dp[now][rem]!=-1)return dp[now][rem];
    ll value = 2e18;

    for(int i=0;;i++){

        ll t = p(primes[now], i);
        if(t>1e18)break;
        if(rem%(ll)(i+1LL)!=0)continue;
        ll temp = f(now+1 , rem/(i+1));
        if(temp<0)continue;
        if(temp<=value/t){

            value = min(value , temp*t);
        }

    }

    return dp[now][rem] = value;
}

void sieve()
{
    bs&=0;
    for(int i=2;i<=1000000;i++){

        if(bs[i]==0){

            for(int j=2*i;j<=1000000;j+=i)bs[j]=1;
            primes.push_back(i);
        }
    }
}

int main(void)
{
    sieve();
    memset(dp , -1 ,sizeof(dp));
    scanf("%lld",&n);
    printf("%lld\n",f(0 , n));

    return 0;
}
