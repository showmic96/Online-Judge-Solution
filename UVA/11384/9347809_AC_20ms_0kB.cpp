// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll two[40];

int main(void)
{
    two[0] = 1;
    for(ll i=1;i<40;i++)two[i] = 2*two[i-1];

    ll n;

    while(scanf("%lld",&n)==1){

        ll d = 0;

        while(two[d]<=n)d++;

        printf("%lld\n",d);
    }

    return 0;
}
