// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD =  2000000011;

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

        ll n;
        scanf("%lld",&n);
        printf("Case #%d: %lld\n",++c , BM(n , n-2 , MOD));
    }
    return 0;
}
