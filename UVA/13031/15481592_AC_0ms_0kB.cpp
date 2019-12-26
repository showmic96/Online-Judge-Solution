// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll , ll > > v;
int n;

bool cmp(pair<ll , ll>A , pair<ll , ll>B)
{
    return A.second<B.second;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        v.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++){

            ll in1 , in2;
            scanf("%lld %lld",&in1 , &in2);
            v.push_back(make_pair(in1 , in2));
        }
        sort(v.begin() , v.end() , cmp);
        ll ans = 0;

        for(int i=0;i<n;i++){

            ll temp = v[i].second , counter = 0;
            for(int j=i;j<n;j++){

                counter+=temp*v[j].first;
            }
            ans = max(ans , counter);
        }

        printf("Case %d: %lld\n",++c , ans);
    }
    return 0;
}
