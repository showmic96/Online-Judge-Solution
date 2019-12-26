// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll cat[26];
    cat[0] = 1;

    for(ll i=1;i<=25;i++){

        cat[i] = 2.00*((double)2.00*i+1)/((double)i+2)*cat[i-1];
    }

    ll n;
    while(scanf("%lld",&n)==1){

        int ans = 0;

        for(int i=1;i<=25;i++){

            if(cat[i]==n){
                ans = i;
            }
        }

        printf("%d\n",ans+1);
    }

    return 0;
}
