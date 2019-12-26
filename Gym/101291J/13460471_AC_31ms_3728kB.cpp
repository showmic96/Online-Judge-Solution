// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(pair<int , int > A , pair<int , int> B)
{
    return A.first>B.first;
}

int main(void)
{
    ll n , k;
    scanf("%lld %lld",&n , &k);
    vector<pair<ll , ll > >v1 , v2;

    for(int i=0;i<n;i++){

        ll in1 , in2;
        scanf("%lld %lld",&in1 , &in2);
        if(in1<0)v2.push_back(make_pair(abs(in1) , in2));
        else v1.push_back(make_pair(in1 , in2));
    }

    ll ans = 0;

    sort(v1.begin() , v1.end() , cmp);

    sort(v2.begin() , v2.end() , cmp);

    for(int i=0;i<v1.size();i++){

        if(v1[i].second==0)continue;
        ll temp = (v1[i].second+k-1)/k;
        ans+=temp*v1[i].first*2;

        ll rem = (temp*k) - v1[i].second;

        for(int j=i+1;j<v1.size();j++){

            if(rem==0)break;

            ll t = min(v1[j].second , rem);
            v1[j].second-=t;
            rem-=t;
        }
    }

    for(int i=0;i<v2.size();i++){

        if(v2[i].second==0)continue;
        ll temp = (v2[i].second+k-1)/k;
        ans+=temp*v2[i].first*2;

        ll rem = (temp*k) - v2[i].second;

        for(int j=i+1;j<v2.size();j++){

            if(rem==0)break;

            ll t = min(v2[j].second , rem);
            v2[j].second-=t;
            rem-=t;
        }
    }

    printf("%lld\n",ans);

    return 0;
}
