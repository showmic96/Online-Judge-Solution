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
        double counter = 1;
        ll ans = 0;

        for(int i=1;i<=n;i++){

            counter*= (double)1.00*(n-i)/(double)n;
            ans = i;
            if(1-counter>=0.5)break;
        }

        printf("Case %d: %lld\n",++c , ans);
    }
    return 0;
}
