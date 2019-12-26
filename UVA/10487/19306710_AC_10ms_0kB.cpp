// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n , c = 0;
    while(scanf("%d",&n)==1){
        if(n==0)break;
        vector<ll>v(n);
        for(auto &x:v)scanf("%lld",&x);
        printf("Case %d:\n",++c);
        int m;
        scanf("%d",&m);
        while(m--){
            ll ans = 0 , dif = 1e18 , now;
            scanf("%lld",&now);
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    ll temp = v[i]+v[j];
                    if(dif>abs(temp-now)){
                        ans = temp;
                        dif = abs(temp-now);
                    }
                }
            }
            printf("Closest sum to %lld is %lld.\n",now , ans);
        }
    }
    return 0;
}
