// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        ll n;
        scanf("%lld",&n);

        vector<ll>v;

        for(ll i=2;;i++){

            if(n%i==0){

                v.push_back(i);
                if(v.size()==2)break;
            }
        }

        printf("Case #%d: %lld = %lld * %lld = %lld * %lld\n",++c , n , n/v[0] , v[0] , n/v[1] , v[1]);
    }

    return 0;
}
