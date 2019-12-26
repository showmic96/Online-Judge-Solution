// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll , ll> > v;

bool cmp(pair<ll , ll> A , pair<ll , ll> B)
{
    if(A.first==B.first)return A.second>B.second;
    return A.first>B.first;
}
int main(void)
{
    ll n , m;
    while(scanf("%lld %lld",&n , &m)==2){

        v.clear();
        for(int i=0;i<n;i++)v.push_back(make_pair(0 , i));

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                ll in;
                scanf("%lld",&in);
                v[j].first+=in;
            }
        }

        sort(v.begin() , v.end() , cmp);
        printf("%lld\n",v[0].second+1);
    }

    return 0;
}
