// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6;

bool isPrime[MAX+9];
vector<ll>primes , v;

void seive()
{
    for(int i=0;i<=MAX;i++)isPrime[i] = true;

    for(int i=2;i<=MAX;i++){

        if(isPrime[i]){

            for(int j=2*i;j<=MAX;j+=i){

                isPrime[j] = false;
            }

            primes.push_back(i);
        }
    }

    int si = primes.size();

    for(int i=0;i<si;i++){

        ll temp = primes[i];

        while(temp<=1000000000000LL){

            temp*=primes[i];
            v.push_back(temp);
        }
    }

    sort(v.begin() , v.end());
}

int main(void)
{
    seive();

    int t;
    scanf("%d",&t);

    while(t--){

        ll a , b;
        scanf("%lld %lld",&a , &b);

        ll ans = upper_bound(v.begin() , v.end() , b) - lower_bound(v.begin() , v.end() , a);
        printf("%lld\n",ans);
    }

    return 0;
}
