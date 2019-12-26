// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll , ll> >v;

bool cmp(pair<ll , ll> A , pair<ll , ll> B)
{
    return A.first<B.first;
}

ll f(ll i , ll last , ll tot)
{
    if(i==v.size())return tot;

    ll value = f(i+1 , last , tot);

    if(v[i].first>=last){

        value = max(value , f(i+1 , v[i].second , tot+1));
    }
    return value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        v.clear();

        ll in1 ,in2;
        while(scanf("%lld %lld",&in1 , &in2)==2){

            if(in1==0&&in2==0)break;
            v.push_back(make_pair(in1 , in2));
        }

        sort(v.begin() , v.end() , cmp);

        printf("%lld\n",f(0 , 0 , 0));
    }

    return 0;
}
