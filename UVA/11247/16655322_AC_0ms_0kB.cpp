// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll m , x;

    while(scanf("%lld %lld",&m, &x)==2){

        if(m==0&&x==0)break;

        if(x==100){printf("Not found\n") ; continue;}

        ll ans = 100*(m-1)/(100.00-x);

        if((100*(m-1))%(100-x)==0)ans--;

        if(ans<m)printf("Not found\n");
        else printf("%lld\n",ans);
    }
    return 0;
}
