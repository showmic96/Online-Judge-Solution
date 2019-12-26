// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll BM(ll a , ll b , ll M)
{
    if(b==0)return 1%M;

    ll x = BM(a , b/2 , M);
    x = (x*x)%M;
    if(b%2==1)x = (x*a)%M;

    return x;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        ll n , k;
        scanf("%lld %lld",&n , &k);

        double x = 1.00*k*log10(1.00*n);
        x-=(ll)x;

        ll ans = pow(10 , x)*100;

        printf("Case %d: %lld %03lld\n",++c , ans , BM(n , k , 1000));
    }

    return 0;
}
