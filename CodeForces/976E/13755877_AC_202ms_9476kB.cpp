// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(pair<ll , ll> A , pair<ll , ll> B)
{
    return A.first-A.second>B.first-B.second;
}

int main(void)
{
    ll n , a , b;
    scanf("%lld %lld %lld",&n , &a , &b);

    vector<pair<ll , ll> > v;

    for(int i=0;i<n;i++){

        ll in1 , in2;
        scanf("%lld %lld",&in1 , &in2);

        v.push_back(make_pair(in1 , in2));
    }

    sort(v.begin() , v.end() , cmp);

    ll sum = 0;

    for(int i=0;i<n;i++){

        if(i<b)sum+=max(v[i].first , v[i].second);
        else sum+=v[i].second;
    }

    ll ans = sum , temp = (1LL<<a);

    if(b>0)for(int i=0;i<n;i++){

        ll t = sum;

        if(i<b){

            t-=max(v[i].first , v[i].second);
            t+=v[i].first*temp;
        }
        else{

            t-=v[i].second;
            t-=max(v[b-1].first , v[b-1].second);
            t+=v[b-1].second;
            t+=v[i].first*temp;
        }

        ans = max(ans , t);
    }

    printf("%lld\n",ans);

    return 0;
}
