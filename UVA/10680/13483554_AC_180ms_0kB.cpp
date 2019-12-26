// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1000000+9;

bool isPrime[MAX+9];
vector<ll>primes;

void sieve()
{
    for(int i=0;i<=MAX;i++)isPrime[i] = true;

    for(int i=2;i<=MAX;i++){

        if(isPrime[i]==true){

            for(int j=2*i;j<=MAX;j+=i)isPrime[j] = false;
            primes.push_back(i);
        }
    }
}

int main(void)
{
    sieve();

    ll n;
    while(scanf("%lld",&n)==1){
        if(!n)break;

        int two = 0 , five = 0;

        for(ll i=2;i<=n;i*=2)two++;
        for(ll i=5;i<=n;i*=5)five++;

        ll ans = 1;
        for(int i=0;i<two-five;i++){

            ans*=2;
            ans%=10;
        }

        for(int i=0;i<primes.size();i++){

            if(primes[i]==2)continue;
            if(primes[i]==5)continue;

            for(ll j=primes[i];j<=n;j*=primes[i]){

                ans*=primes[i];
                ans%=10;
            }
        }

        printf("%lld\n",ans);
    }
    return 0;
}
