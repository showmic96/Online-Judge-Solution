// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e8+9;
bool bs[MAX+9];
vector<ll>primes , multi;

void sieve()
{
    for(int i=0;i<=MAX;i++)bs[i] = true;
    for(int i=4;i<=MAX;i+=2)bs[i] = false;

    primes.emplace_back(2);
    for(int i=3;i<=MAX;i+=2){

        if(bs[i]==true){

            primes.emplace_back(i);
            for(int j=2*i;j<=MAX;j+=i){

                bs[j] = false;
            }
        }
    }

    int si = primes.size();
    for(int i=0;i<si;i++){

        multi.emplace_back(primes[i]*primes[i]);
    }
}

ll power(ll a , ll lim)
{
    ll temp = 1;
    for(int i=0;i<lim;i++)temp*=a;
    return temp;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    sieve();

    int t;
    cin >> t;
    while(t--){

        ll n , ans = 1 , temp;
        cin >> n;

        temp = n;

        for(int i=0;multi[i]<=n;i++){

            if(n%primes[i]==0){

                ll c = 0;
                while(n%primes[i]==0){

                    c++;
                    n/=primes[i];
                }

                ans*=(power(primes[i] , c+1)-1)/(primes[i]-1);
            }
        }

        if(n>1)ans*=(n+1LL);

        cout << ans-temp << endl;
    }

    return 0;
}
