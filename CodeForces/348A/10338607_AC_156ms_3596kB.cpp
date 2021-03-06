// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll>v;
int n;

bool possible(ll x)
{
    ll sum = 0;

    for(int i=0;i<n;i++){

        if(v[i]>x)return false;

        sum+=(x-v[i]);
    }

    if(sum>=x)return true;
    return false;
}

int main(void)
{
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v.push_back(in);
    }

    sort(v.begin() , v.end());

    ll hi = 1e10 , low = 0 , mid , t = 200 , ans = 0;

    while(t--){

        mid = (hi+low)/2;

        if(possible(mid)==true){

            hi = mid-1;
            ans = mid;
        }
        else{
            low = mid+1;
        }
    }

    printf("%lld\n",ans);

    return 0;
}
