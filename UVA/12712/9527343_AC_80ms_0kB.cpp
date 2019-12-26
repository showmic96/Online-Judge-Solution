// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 10000000000007;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll n , m , l;
        scanf("%lld %lld %lld",&n , &m , &l);

        ll temp = n*n;

        for(ll i=1;i<m;i++){

            temp = temp*(n*n - i);
            temp%=MOD;
        }

        ll ans = temp;

        for(ll i=m;i<l;i++){

            temp = temp*(n*n - i);
            temp%=MOD;
            ans+=temp;
            ans%=MOD;
        }

        printf("Case %d: %lld\n",++c , ans);
    }
    return 0;
}
