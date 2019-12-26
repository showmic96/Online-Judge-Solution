// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , k , x;
vector<ll>v;

ll l[200005] , r[200005];


int main(void)
{
    memset(l , 0 , sizeof(l));
    memset(r , 0 , sizeof(r));

    scanf("%lld %lld %lld",&n , &k , &x);

    v.push_back(0);

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v.push_back(in);
    }
    v.push_back(0);

    for(int i=1;i<=n;i++)l[i] = l[i-1]|v[i];
    for(int i=n;i>=1;i--)r[i] = r[i+1]|v[i];

    ll mx = 1 , ans = 0;
    for(int i=0;i<k;i++)mx*=x;

    for(int i=1;i<=n;i++){

        ans = max(ans , l[i-1]|(v[i]*mx)|r[i+1]);
    }

    printf("%lld\n",ans);
    return 0;
}
