// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n , m;
vector<int>v1 , v2;
ll f(ll now)
{
    ll tot = 0;
    for(auto i:v1){
        if(i<now)tot+=now-i;
    }
    for(auto i:v2){
        if(i>now)tot+=i-now;
    }
    return tot;
}
int main(void)
{
    ll l = 1e16 , r = -1e16 , t = 200 , ans = 1e16;
    scanf("%d %d",&n , &m);
    for(int i=0;i<n;i++){
        ll in;
        scanf("%lld",&in);
        v1.push_back(in);
        r = max(r , in);
        l = min(l , in);
    }
    for(int i=0;i<m;i++){
        ll in;
        scanf("%lld",&in);
        v2.push_back(in);
        l = min(l , in);
        r = max(r , in);
    }
    while (t--) {
        ll mid1 = l + (r - l) / 3;
        ll mid2 = r - (r - l) / 3;
        ll f1 = f(mid1);
        ll f2 = f(mid2);

        if (f1>f2) {
            l = mid1 - 1;
        }
        else{
            r = mid2 + 1;
        }
    }
    if(l>r)swap(l , r);
    for(ll i=l-10;i<=r+10;i++)ans = min(ans , f(i));
    printf("%lld\n",ans);
    return 0;
}
