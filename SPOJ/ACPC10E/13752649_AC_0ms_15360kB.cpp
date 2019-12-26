// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll g , t , a , d;
    while(scanf("%lld %lld %lld %lld",&g , &t , &a , &d)==4){

        if(g==-1&&t==-1&&a==-1&&d==-1)break;

        ll total = g*a+d , now = 1;

        while(now<total)now*=2;

        ll add = now-total;
        ll match = (double)t*(t-1)/2.00;
        match*=g;
        match+=now-1;

        printf("%lld*%lld/%lld+%lld=%lld+%lld\n",g , a , t , d , match , add);

    }
    return 0;
}
