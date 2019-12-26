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

        ll n , k , m , sum = 0;
        scanf("%lld %lld %lld",&n , &k , &m);

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            sum+=in;
            sum%=m;
        }

        ll temp = BM(n , k-1 , m);

        ll ans = (temp*sum)%m;
        ans*=k;
        ans%=m;

        printf("Case %d: %lld\n",++c , ans);
    }

    return 0;
}
