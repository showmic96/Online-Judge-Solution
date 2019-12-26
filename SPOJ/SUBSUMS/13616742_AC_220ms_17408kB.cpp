// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , a , b , lim;

vector<ll>v , v1 , v2;

void f1(int i , ll sum)
{
    if(i==lim){

        v1.push_back(sum);
        return ;
    }

    f1(i+1 , sum);
    f1(i+1 , sum+v[i]);
}

void f2(int i , ll sum)
{
    if(i==n){

        v2.push_back(sum);
        return ;
    }

    f2(i+1 , sum);
    f2(i+1 , sum+v[i]);
}

int main(void)
{
    scanf("%lld %lld %lld",&n , &a , &b);

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v.push_back(in);
    }

    lim = (n/2);

    f1(0 , 0);
    f2(lim , 0);

    sort(v2.begin() , v2.end());
    ll ans = 0;

    for(int i=0;i<v1.size();i++){

        ans+=upper_bound(v2.begin() , v2.end() , b-v1[i])-lower_bound(v2.begin() , v2.end() , a-v1[i]);
    }

    printf("%lld\n",ans);

    return 0;
}
