// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int>v(n);
        for(auto &x:v)scanf("%d",&x);
        sort(v.begin() , v.end());
        ll ans = 1;
        for(int i=0;i<n;i++){
            ans*=(v[i]-i+MOD)%MOD;
            ans%=MOD;
        }
        printf("Case %d: %lld\n",++c , ans);
    }
    return 0;
}
