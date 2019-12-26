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

        ll ans = n%2;
        if(ans==0)ans = 2;

        if(m==1)printf("2\n");
        else printf("%lld\n",ans);
    }
    return 0;
}
