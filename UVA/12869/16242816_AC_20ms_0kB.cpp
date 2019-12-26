// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a , b;
    while(scanf("%lld %lld",&a , &b)==2){
        if(a==0&&b==0)break;
        printf("%lld\n",b/5-a/5+1);
    }
    return 0;
}
