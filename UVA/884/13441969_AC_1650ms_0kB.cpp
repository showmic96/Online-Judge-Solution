// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6+9;
ll ar[MAX+9];

ll fact(ll x)
{
    int counter = 0;
    for(ll i=2;i*i<=x;i++){

        while(x%i==0){

            counter++;
            x/=i;
        }
    }

    if(x>1)counter++;
    return counter;
}

void sieve()
{
    memset(ar , 0 , sizeof(ar));

    for(int i=2;i<=MAX;i++){

        ar[i] = ar[i-1] + fact(i);
    }
}

int main(void)
{
    sieve();
    ll n;

    while(scanf("%lld",&n)==1){

        printf("%lld\n",ar[n]);
    }
    return 0;
}
