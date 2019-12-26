// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(pair<ll , ll > A , pair<ll , ll> B)
{
    return A.second<B.second;
}

int main(void)
{
    int n;
    scanf("%d",&n);

    vector<pair<ll, ll> > v;

    for(int i=0;i<n;i++){

        ll in1 , in2;
        scanf("%lld %lld",&in1 , &in2);
        v.push_back(make_pair(in1 , in2));
    }

    sort(v.begin() , v.end() , cmp);

    ll last = -1 , counter = 0;

    for(int i=0;i<n;i++){

        if(v[i].first>last){

            counter++;
            last = v[i].second;
        }
    }

    printf("%lld\n",counter);

    return 0;
}
