// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n , m;

ll f(ll x)
{
    ll sum = 0;
    for(ll i=x;i<=m;i*=x){

        sum+=m/i;
    }

    return sum;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%lld %lld",&n , &m);

        ll ans = 1e9 , temp = n;

        for(ll i=2;i*i<=temp;i++){

            if(n%i==0){

                ll t= 1;
                ll counter = 0;
                while(n%i==0){

                    t*=i;
                    n/=i;
                    counter++;
                }

                ans = min(ans , f(i)/counter);
            }
        }

        if(n>1){ans = min(ans , f(n));}

        printf("Case %d:\n",++c);
        if(ans>0)printf("%lld\n",ans);
        else printf("Impossible to divide\n");
    }
    return 0;
}
