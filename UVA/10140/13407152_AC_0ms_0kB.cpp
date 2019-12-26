// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 9;

bitset<MAX>vis;
vector<ll>primes , v;

void seive()
{
    vis = 0;

    for(int i=2;i<=MAX;i++){

        if(vis[i]!=true){

            for(int j=2*i;j<=MAX;j+=i)vis[j] = true;

            primes.push_back(i);
        }
    }
}

void f(ll a , ll b)
{
    ll lim1 = sqrt(b)+1 , lim2 = primes.size();
    v.clear();
    vis = 0;

    if(b==2)return ;
    if(b<2)return ;
    if(a<2)a = 2;

    for(ll i=0;primes[i]<=lim1&&i<lim2;i++){

        ll temp = a/primes[i];

        if(a%primes[i])temp++;

        temp*=primes[i];

        if(temp==primes[i])temp+=primes[i];

        for(ll j=temp;j<=b;j+=primes[i])vis[j-a] = true;
    }

    int counter = 0;

    for(ll i=a;i<=b;i++)if(vis[i-a]==false)v.push_back(i);

    return ;
}

int main(void)
{
    seive();

    ll l , r;
    while(scanf("%lld %lld",&l , &r)==2){

        f(l , r);
        if(v.size()<2)printf("There are no adjacent primes.\n");
        else{

            ll mx = 0 , mi = 1e9 , d1 , d2 , c1 , c2;

            for(int i=0;i<v.size()-1;i++){

                int temp = v[i+1]-v[i];
                if(temp>mx){

                    mx = temp;
                    c1 = v[i];
                    c2 = v[i+1];
                }

                if(mi>temp){

                    mi = temp;
                    d1 = v[i];
                    d2 = v[i+1];
                }
            }

            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",d1 , d2 , c1 , c2);
        }
    }

    return 0;
}
