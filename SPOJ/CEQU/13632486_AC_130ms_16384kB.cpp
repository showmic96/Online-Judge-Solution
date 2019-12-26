// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , tc = 0;
    scanf("%d",&t);

    while(t--){

        ll a , b , c;
        scanf("%lld %lld %lld",&a , &b , &c);

        if(c%__gcd(a , b))printf("Case %d: No\n",++tc);
        else printf("Case %d: Yes\n",++tc);
    }

    return 0;
}
