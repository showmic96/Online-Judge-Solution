// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool f(ll x)
{
    if(x==2)return true;
    if(x==1)return false;
    if(x%2==0)return false;

    for(ll i=3;i*i<=x;i+=2){

        if(x%i==0)return false;
    }

    return true;
}

int main(void)
{
    ll n;

    while(scanf("%lld",&n)==1){

        if(!n)break;

        ll temp = 1;
        for(int i=0;i<n;i++){

            temp*=2;
        }

        ll now = (temp-1)*(temp/2LL);

        if(f(n)&&f(temp-1))printf("Perfect: %lld!\n",now);
        else if(f(n)||f(temp-1))printf("Given number is prime. But, NO perfect number is available.\n");
        else printf("Given number is NOT prime! NO perfect number is available.\n");
    }

    return 0;
}
