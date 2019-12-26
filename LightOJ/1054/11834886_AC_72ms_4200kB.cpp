// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6+9;
bool isPrime[MAX+9];
vector<ll>primes;

ll MOD = 1000000007;

ll BM(long long a, long long b, long long M)
{
    if(b==0)return 1%M;
    ll x = BM(a , b/2 , M);
    x = (x*x)%M;
    if(b%2==1)x = (x*a)%M;
    return x;
}

void seive()
{
    for(int i=0;i<=MAX;i++)isPrime[i] = true;

    for(int i=2;i<=MAX;i++){

        if(isPrime[i]==true){

            for(int j=2*i;j<=MAX;j+=i){

                isPrime[j] = false;
            }

            primes.push_back(i);
        }
    }
}

int main(void)
{
    seive();

    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll n , m;
        scanf("%lld %lld",&n , &m);

        vector<pair<ll, int> >v;

        for(int i=0;primes[i]*primes[i]<=n&&i<primes.size();i++){

            if(n%primes[i]==0){

                ll counter = 0;

                while(n%primes[i]==0){

                    n/=primes[i];
                    counter++;
                }

                v.push_back(make_pair(primes[i] , counter));
            }
        }

        if(n>1){

            v.push_back(make_pair(n , 1));

        }

        int si = v.size();

        ll ans = 1;

        for(int i=0;i<si;i++){

            ll lim = v[i].second;

            lim*=m;
            lim++;

            ll x = ((BM(v[i].first , lim , MOD)-1)+MOD)%MOD;
            ll y = BM((v[i].first-1), MOD-2 , MOD)%MOD;

            ans = (ans%MOD * x%MOD * y%MOD)%MOD;

        }

        printf("Case %d: %lld\n",++c , ans);
    }
    return 0;
}
