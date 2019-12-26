// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n , m , w , temp[200005];
vector<ll>v;

bool possible(ll mid)
{
    memset(temp , 0 , sizeof(temp));
    ll counter = 0;
    for(int i=0;i<n;i++){
        if(i>0)temp[i]+=temp[i-1];
        ll now = max(0LL , mid-v[i]-temp[i]);
        counter+=now;
        if(counter>m)return false;
        temp[i]+=now;
        temp[i+w]-=now;
    }
    return true;
}

int main(void)
{
    scanf("%lld %lld %lld",&n , &m, &w);
    for(int i=0;i<n;i++){
        ll in;
        scanf("%lld",&in);
        v.push_back(in);
    }
    ll hi = 1e16 , low = 0 , mid , t = 100 , ans = -1;
    while(t--){
        mid = (hi+low)/2;
        if(possible(mid)){
            low = mid+1;
            ans = mid;
        }
        else hi = mid-1;
    }
    printf("%lld\n",ans);
    return 0;
}
