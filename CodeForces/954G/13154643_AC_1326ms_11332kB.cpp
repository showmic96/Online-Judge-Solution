// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , r , k;
vector<ll>v , temp;

bool f(ll x)
{
    ll t = k;
    if(temp[0]<x){

        ll tt = x-temp[0];
        if(tt>t)return false;
        temp[0]+=tt;
        temp[min(n , 2*r+1)]-=tt;
        t-=tt;
    }

    for(int i=1;i<n;i++){

        temp[i]+=temp[i-1];
        if(temp[i]<x){

            ll tt = x-temp[i];
            if(tt>t)return false;
            temp[i]+=tt;
            temp[min(n , i+2*r+1)]-=tt;
            t-=tt;
        }
    }

    return true;
}

int main(void)
{
    scanf("%lld %lld %lld",&n , &r , &k);

    for(int i=0;i<=n;i++)v.push_back(0);
    ll mx = 0;
    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);

        v[max((ll)0 , i-r)]+=in;
        v[min(n , i+r+1)]-=in;
        mx = max(mx , in);
    }
    ll hi = 2e18 , low = 0 , mid;
    ll ans = -1 , t = 200;

    while(t--){

        mid = (hi+low)/2;

        temp = v;
        if(f(mid)==true){

            ans = mid;
            low = mid+1;
        }

        else hi = mid-1;
    }

    printf("%lld\n",ans);

    return 0;
}
