// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll , ll> > v;
int n;

ll f(int i , ll now , ll need , ll multi)
{
    if(i==v.size()){

        if(now>=need)return 0;
        return 1e17;
    }

    ll value = f(i+1 , now , need , multi);
    if(now<need)value = min(value , f(i+1 , now+v[i].first*multi , need , multi)+v[i].second);
    return value;
}

int main(void)
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){

        ll in1 , in2;
        scanf("%lld %lld",&in1 , &in2);
        v.push_back(make_pair(in1 , in2));
    }

    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){

        ll in1 , in2;
        scanf("%lld %lld",&in1 , &in2);

        ll ans = f(0 , 0 , in1 , in2);

        if(ans>=1e17)printf("Case %d: IMPOSSIBLE\n",i+1);
        else printf("Case %d: %lld\n",i+1 , ans);
    }

    return 0;
}
