// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n;
    while(scanf("%lld",&n)==1){

        if(!n)break;

        ll now = n/9*10;
        bool check = false;

        for(ll i=max(10LL , now-10);i<=now+10;i++){

            if(i-(ll)(i/10)==n){

                if(check)printf(" ");check = true;
                printf("%lld",i);
            }
        }

        printf("\n");
    }
    return 0;
}
