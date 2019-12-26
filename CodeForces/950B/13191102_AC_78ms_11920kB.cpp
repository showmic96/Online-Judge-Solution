// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n , m;
    scanf("%lld %lld",&n , &m);

    vector<ll>v;
    map<ll , int>mp;

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v.push_back(in);
    }

    mp[v[0]] = 1;

    for(int i=1;i<n;i++){

        v[i]+=v[i-1];
        mp[v[i]] = 1;
    }

    ll sum = 0;
    int counter = 0;

    for(int i=0;i<m;i++){

        ll in;
        scanf("%lld",&in);
        sum+=in;

        if(mp[sum])counter++;
    }

    printf("%d\n",counter);

    return 0;
}
