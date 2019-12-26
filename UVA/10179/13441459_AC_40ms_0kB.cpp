// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll phi(ll n)
{
    ll ans = n;
    for(ll i=2;i*i<=n;i++){

        if(n%i==0){

            while(n%i==0){

                n/=i;
            }

            ans-=ans/i;
        }
    }

    if(n>1)ans-=ans/n;
    return ans;
}

int main(void)
{
    ll n;
    while(scanf("%lld",&n)==1){

        if(!n)break;
        printf("%lld\n",phi(n));

    }
    return 0;
}
