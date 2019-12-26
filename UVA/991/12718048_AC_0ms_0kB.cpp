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
    bool check = false;
    while(scanf("%lld",&n)==1){
        if(check)printf("\n");check = true;
        printf("%lld\n",cat[n-1]);
    }

    return 0;
}
