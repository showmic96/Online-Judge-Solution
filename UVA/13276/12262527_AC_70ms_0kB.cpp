// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll e , p , k , r;

bool possible(ll x)
{
    ll temp = (x*p*k)-(x-1)*r;
    if(temp>=e)return true;
    return false;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%lld %lld %lld %lld",&e , &p , &k , &r);

        if(p*k>=e)printf("Case %d: %lld\n",++c , (ll)(double)ceil(1.00*e/p));
        else if(p*k<=r)printf("Case %d: -1\n",++c);
        else{

            ll hi = 1e9 , low = 1 , mid , ans = 0 , cc = 200;

            while(cc--){

                mid = (hi+low)/2;
                if(possible(mid)==true){

                    hi = mid-1;
                    ans = mid;
                }

                else{

                    low = mid+1;
                }
            }

            ll fin = (ans-1)*k;
            ll temp = e-fin*p;
            temp+=(ans-1)*r;

            fin+=(ll)(double)ceil(1.00*temp/p);

            printf("Case %d: %lld\n",++c , fin);
        }
    }
    return 0;
}
