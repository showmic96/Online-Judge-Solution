// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll two[61];

int main(void)
{
    two[0] = 1;
    for(ll i=1;i<=60;i++)two[i] = two[i-1]*2LL;

    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll d , n , last;
        scanf("%lld %lld",&d , &n);
        if(n==0){
            printf("Case %d: YES 0\n",++c);
            continue;
        }
        for(int i=d;i>=0;i--){

            if(two[i]<=n){

                n-=two[i];
                last = i;
            }
        }
        if(n>0)printf("Case %d: NO\n",++c);
        else printf("Case %d: YES %d\n",++c , d-last+1);
    }
    return 0;
}
