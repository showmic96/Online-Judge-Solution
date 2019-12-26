// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll x;
        scanf("%lld",&x);

        ll i;
        ll ans = x;
        ll last = x;
        if(x!=1)ans+=1;

        for(i=2;i*i<=x;i++){

            ll temp = x/i;
            ans+=temp;
            ans+=(last-temp-1)*(i-1);
            last = temp;

            if(temp!=i)ans+=i;
        }

        for(;i<last;i++)ans+=x/i;

        printf("Case %d: %lld\n",++c , ans);
    }
    return 0;
}
