// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll cat[30] , cat2[30];
    cat[0] = 1;
    cat[1] = 1;
    cat2[0] = 1;
    cat2[1] = 1;
    cat2[2] = 1;
    cat2[3] = 3;

    for(ll i=1;i<30;i++){

        cat[i] = cat[i-1]*2*(2*i+1)/(i+2);
    }

    for(ll i=4;i<30;i++){

        cat2[i] = (3*(2*i-3)*cat2[i-1]-(i-3)*cat2[i-2])/i;
    }

    int n;
    while(scanf("%d",&n)==1){

        printf("%lld\n",cat2[n]-cat[max(0, n-2)]);
    }

    return 0;
}
