// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll k;
    int c = 0;
    while(scanf("%lld",&k)==1){

        ll n = -1 , m = -1;
        for(ll i=2;i<=1000000;i++){

            if(i*i>k){
                n = k;
                m = k-1;
            }
            ll now = 1;

            for(ll j=i;j<=10000000;j++){

                now*=j;
                if(now==k){
                    n = j;
                    m = i-1;
                    break;
                }
                if(now>k)break;
            }
            if(n!=-1)break;
        }
        if(m==0)printf("Case %d: Impossible\n",++c);
        else printf("Case %d: %lld %lld\n",++c , n , m);
    }

    return 0;
}
