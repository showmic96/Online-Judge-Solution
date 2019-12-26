// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , l , u;

vector<int> make(ll x)
{
    vector<int>v;
    while(x){

        v.push_back(x%2);
        x/=2;
    }

    while(v.size()!=50)v.push_back(0);

    reverse(v.begin() , v.end());
    return v;
}

ll get(vector<int>v)
{
    ll ans = 0;
    for(int i=0;i<50;i++){

        ans*=2;
        ans+=v[i];
    }

    return ans;
}
int main(void)
{
    while(scanf("%lld %lld %lld",&n , &l , &u)==3){

        vector<int>v1 = make(n);
        vector<int>v2 = make(0);

        for(int i=0;i<50;i++){

            if(v1[i]!=v2[i]){

                v2[i] = 1;
                ll x = get(v2);

                if(x<=l)continue;
                v2[i] = 0;
            }

            else{

                v2[i] = 1;
                ll x = get(v2);

                if(x<=u)continue;
                v2[i] = 0;
            }
        }

        ll ans = get(v2);

        printf("%lld\n",ans);
    }
    return 0;
}
