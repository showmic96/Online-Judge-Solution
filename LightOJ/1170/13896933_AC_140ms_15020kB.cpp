// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

set<ll>st;
set<ll>::iterator it;
vector<ll>v;
ll dp[100005];
ll MOD = 100000007;

void pre()
{
    for(ll i=2;i<100005;i++){

        ll temp = i;

        while(temp<10000000000LL){

            temp*=i;
            st.insert(temp);
        }
    }

    for(it = st.begin();it!=st.end();it++)v.push_back(*it);
}

ll ext_gcd ( ll A, ll B, ll *X, ll *Y ){
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

inline ll MI ( ll a, ll m ) {
    ll x, y;
    ext_gcd( a, m, &x, &y );
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}

ll f(ll x)
{
    if(x<1)return 0;
    return dp[x];
}

int main(void)
{
    pre();
    dp[0] = 1;

    for(ll i=0;i<100005;i++){

        dp[i+1] = (((2*(2*i+1)*dp[i])%MOD)*(MI(i+2 , MOD)%MOD))%MOD;

    }
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        ll a , b;
        scanf("%lld %lld",&a , &b);

        ll temp = upper_bound(v.begin() , v.end() , b) - lower_bound(v.begin() , v.end() , a);

        printf("Case %d: %lld\n",++c , f(temp));
    }
    return 0;
}
