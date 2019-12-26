// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll value[12345] , sum[12345] , MAX = 0;

void pre_cal()
{
    value[1] = 1;
    value[2] = 1;

    for(int i=3;;i++){

        value[i] = value[i-1]+value[i-2];
        value[i]%=100;

        MAX++;
        if(i!=2)if(value[i]==1&&value[i-1]==1)break;
    }

    sum[0] = 0;

    for(int i=1;i<=MAX;i++){

        sum[i] = sum[i-1]+value[i];
    }
}

ll f(ll x)
{
    ll temp = sum[MAX]*(x/MAX) + sum[x%MAX];

    return temp;
}

int main(void)
{
    pre_cal();
    int t;
    scanf("%d",&t);
    while(t--){

        ll a, b;
        scanf("%lld %lld",&a , &b);

        printf("%lld\n",f(b)-f(a-1));
    }
    return 0;
}
