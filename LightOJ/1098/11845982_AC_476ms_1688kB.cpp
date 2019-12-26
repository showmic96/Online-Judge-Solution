// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll n)
{
    ll ans = 0;
    ll i;
    for(i = 2;i*i<n;i++){

        ll temp = n/i;

        ans+= (i*(temp-i+1)) + (temp*(temp+1)/2) - (i*(i+1)/2);
    }

    if(i*i==n)ans+=i;

    return ans;
}

int main(void)
{
    int t , c=0;
    scanf("%d",&t);
    while(t--){

        ll n;
        scanf("%lld",&n);
        printf("Case %d: %lld\n",++c , f(n));
    }
    return 0;
}
