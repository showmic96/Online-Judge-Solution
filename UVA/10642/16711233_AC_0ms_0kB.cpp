// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll x1 , y1 , x2 , y2;
        scanf("%lld %lld %lld %lld",&y1 , &x1 , &y2 , &x2);
        ll counter = 0;

        while(y1!=0){

            x1++;
            y1--;
            counter--;
        }

        while(y2!=0){

            x2++;
            y2--;
            counter++;
        }

        for(ll i=x1;i<x2;i++)counter+=(i+1LL);

        printf("Case %d: %lld\n",++c , counter);
    }
    return 0;
}
