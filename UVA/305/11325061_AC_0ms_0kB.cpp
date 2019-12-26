//In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans[] = {2 , 7 , 5 , 30 , 169 , 441 , 1872 , 7632 , 1740, 93313 , 459901 , 1358657 , 2504881};

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    ll x;

    while(scanf("%lld",&x)==1){

        if(!x)break;

        printf("%lld\n",ans[x-1]);
    }
    return 0;
}
