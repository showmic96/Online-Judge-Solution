// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        ll a , b;
        scanf("%lld %lld",&a , &b);

        ll n = a+b;

        n = (n*(n+1))/2LL;

        printf("%lld\n",n+1+a);
    }
    return 0;
}
