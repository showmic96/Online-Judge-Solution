// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n;
    while(scanf("%lld",&n)==1){

        if(n==0)break;
        ll now = 0;

        for(int i=0;i<35;i++){

            now = (1LL<<i);
            if(now>n)break;
        }
        now--;

        if(n!=now)printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
