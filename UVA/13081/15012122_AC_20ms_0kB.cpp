// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll x)
{
    if(x==0)return 1;
    if(x%4==0)return x+1;
    if(x%4==1)return 0;
    if(x%4==2)return x;
    if(x%4==3)return 1;
}

int main(void)
{

    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll in1 , in2;
        scanf("%lld %lld",&in1 , &in2);

        ll now = f(in1);
        for(ll i=in1+1LL;i<=in2;i++){

            now&=f(i);
            if(now==0)break;
        }

        printf("%lld\n",now);
    }
    return 0;
}
