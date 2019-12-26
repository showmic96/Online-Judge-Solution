// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;
bool isPrime[MAX+9];

vector<ll>primes;

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

ll f(ll x , ll y)
{
    ll ans = 0;

    for(ll i=y;i<=x;i*=y){

        ans+=x/i;
    }

    return ans;
}

int main(void)
{
    ll x , y;
    seive();

    while(scanf("%lld %lld",&x , &y)==2){

        vector<pair<ll , int> >v;

        ll temp = y;

        for(int i=0;primes[i]*primes[i]<=y;i++){

            if(y%primes[i]==0){

                int counter = 0;

                while(y%primes[i]==0){

                    counter++;
                    y/=primes[i];
                }

                v.push_back(make_pair(primes[i] , counter));
            }
        }

        if(y>1)v.push_back(make_pair(y , 1));

        int si = v.size();

        bool check = true;

        for(int i=0;i<si;i++){

            if(f(x , v[i].first)<v[i].second)check = false;
        }

        if(check==true)printf("%lld divides %lld!\n",temp,x);
        else printf("%lld does not divide %lld!\n",temp,x);
    }

    return 0;
}
