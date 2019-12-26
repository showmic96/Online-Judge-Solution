// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>primes;
bitset<10000005>bs;

void seive()
{
    bs&=0;

    for(ll i=2;i<=10000000;i++){

        if(bs[i]==0){

            for(ll j=2*i;j<=10000000;j+=i)bs[j]=1;
            primes.push_back(i);
        }
    }
}

int main(void)
{
    seive();
    ll x;
    while(scanf("%lld",&x)==1){

        if(x==1)break;
        ll ans = 0;

        for(ll i=0;primes[i]*primes[i]<=x;i++){

            if(x%primes[i]==0){

                while(x%primes[i]==0){

                    x/=primes[i];
                    ans++;
                }
            }
        }

        if(x>1)ans++;

        printf("%lld\n",ans);
    }
    return 0;
}
