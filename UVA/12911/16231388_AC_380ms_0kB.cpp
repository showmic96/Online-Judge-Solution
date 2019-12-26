// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , w;
vector<ll>v , v1 , v2;

void f1(int i , ll value)
{
    if(i==n/2){

        v1.push_back(value);
        return ;
    }

    f1(i+1 , value);
    f1(i+1 , value+v[i]);
}

void f2(int i , ll value)
{
    if(i==n){

        v2.push_back(value);
        return ;
    }

    f2(i+1 , value);
    f2(i+1 , value+v[i]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    while(scanf("%lld %lld",&n , &w)==2){

        v.clear();v1.clear();v2.clear();
        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        f1(0 , 0);
        f2(n/2 , 0);

        sort(v2.begin() , v2.end());

        ll ans = 0;

        for(int i=0;i<v1.size();i++){

            ans+=upper_bound(v2.begin() , v2.end() , w-v1[i]) - lower_bound(v2.begin() , v2.end() , w-v1[i]);
        }
        if(w==0)ans--;
        printf("%lld\n",ans);
    }

    return 0;
}
