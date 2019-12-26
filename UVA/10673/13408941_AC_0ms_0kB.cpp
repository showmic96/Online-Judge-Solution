// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        ll n , m;
        scanf("%lld %lld",&n , &m);

        ll t1 = n/m;
        ll t2 = (n+m-1)/m;

        ll ans1, ans2;

        for(int i=0;;i++){

            ll temp = i*t1;

            if((n-temp)%t2==0){

                ans1 = i;
                ans2 = (n-temp)/t2;
                break;
            }
        }

        printf("%lld %lld\n",ans1 , ans2);

    }
    return 0;
}
