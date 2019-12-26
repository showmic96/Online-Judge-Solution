// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e7+9;
bitset<MAX+9>bs;
vector<ll>primes;

void sieve()
{
    bs&=0;
    for(int i=2;i<=MAX;i++){

        if(bs[i]==0){

            for(int j=2*i;j<=MAX;j+=i){

                bs[j] = 1;
            }

            primes.push_back(i);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    sieve();
    ll n;
    while(cin >> n){

        if(!n)break;

        ll counter = 1;

        for(ll i=0;primes[i]*primes[i]<=n;i++){

            if(n%primes[i]==0){

                ll c = 1;
                while(n%primes[i]==0){

                    c++;
                    n/=primes[i];
                }

                counter*=c;
            }
        }

        if(n>1)counter*=2LL;

        if(counter%2==0)cout << "no" << endl;
        else cout << "yes" << endl;
    }

    return 0;
}
