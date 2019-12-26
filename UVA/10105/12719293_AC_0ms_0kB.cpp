// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fact[15];

int main(void)
{
    fact[0] = 1;
    for(int i=1;i<15;i++){

        fact[i] = i*fact[i-1];
    }

    int n , k;
    while(scanf("%d %d",&n , &k)==2){

        ll ans = fact[n];

        for(int i=0;i<k;i++){

            int in;
            scanf("%d",&in);
            ans/=fact[in];
        }

        printf("%lld\n",ans);
    }

    return 0;
}
