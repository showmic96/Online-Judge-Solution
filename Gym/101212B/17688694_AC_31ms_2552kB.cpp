// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6+9;

bool vis[MAX+9];
vector<ll>primes;

void sieve()
{
    for(int i=0;i<=MAX;i++)vis[i] = true;
    for(int i=2;i<=MAX;i++){

        if(vis[i]==true){

            for(int j=2*i;j<=MAX;j+=i)vis[j] = false;
            primes.push_back(i);
        }
    }
}


int main(void)
{
    sieve();

    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        ll n , k , ans = 0;
        scanf("%lld %lld",&n , &k);
        vector<pair<ll , ll > >temp;
        for(int i=0;primes[i]*primes[i]<=k;i++){

            if(k%primes[i]==0){
                ll cc = 0;
                while(k%primes[i]==0){

                    k/=primes[i];
                    cc++;
                }

                temp.push_back({primes[i] , cc});
            }
        }
        if(k>1)temp.push_back({k,1});
        ans = 1e18;

        for(int i=0;i<temp.size();i++){

            ll counter = 0;
            for(ll j=temp[i].first;j<=n;j*=temp[i].first){

                counter+=n/j;
            }

            ans = min(ans , counter/temp[i].second);
        }

        printf("Case %d: %lld\n",++c , ans);
    }
    return 0;
}
