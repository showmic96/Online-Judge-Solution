// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e7+9+1e5;

bitset<MAX+9>bs;
vector<int>primes;

void sieve()
{
    bs&=0;

    for(int i=2;i<=MAX;i++){

        if(bs[i]==0){

            for(int j=2*i;j<=MAX;j+=i)bs[j] = 1;
            primes.push_back(i);
        }
    }

    primes.erase(primes.begin());
}

ll f(ll n)
{
    ll j = upper_bound(primes.begin() , primes.end() , (int)n) - primes.begin();
    ll counter = 0;

    for(ll i=0;i<j;i++){

        while(i<j&&primes[i]+primes[j]>n)j--;
        counter+=j-i;
    }

    return counter;
}

int main(void)
{
    sieve();

    ll l , r;
    while(scanf("%lld %lld",&l , &r)==2){

        if(l==0&&r==0)break;

        printf("%lld\n",f(r)-f(l-1));
    }
    return 0;
}
