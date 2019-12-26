// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(ll x)
{
    int counter = 0;
    while(x){

        if(x%2==1)counter++;
        x/=2;
    }
    return counter;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        ll x;
        scanf("%lld",&x);
        printf("%d\n",f(x));
    }
    return 0;
}
