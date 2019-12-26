// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 9;

bitset<MAX>vis;
vector<ll>primes;

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

ll f(ll a , ll b)
{
    ll lim1 = sqrt(b)+1 , lim2 = primes.size();

    vis = 0;
    if(b==2)return 1;
    if(b<2)return 0;
    if(a<2)a = 2;

    for(ll i=0;primes[i]<=lim1&&i<lim2;i++){

        ll temp = a/primes[i];

        if(a%primes[i])temp++;

        temp*=primes[i];

        if(temp==primes[i])temp+=primes[i];

        for(ll j=temp;j<=b;j+=primes[i])vis[j-a] = true;
    }

    int counter = 0;

    for(ll i=a;i<=b;i++)if(vis[i-a]==false)counter++;

    return counter;

}

int main(void)
{
    seive();

    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        ll a , b;
        scanf("%lld %lld",&a , &b);
        printf("Case %d: %lld\n",++c , f(a , b));
    }

    return 0;
}
