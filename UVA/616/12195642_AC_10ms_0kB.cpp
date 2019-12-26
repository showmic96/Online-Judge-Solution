// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool get(ll n , ll a)
{
    int counter = 0;
    for(int i=0;i<a;i++){

        ll temp = n/a;
        temp += n%a;
        if(n%a>1)return false;
        if(n%a==0)return false;
        n-=temp;
    }

    if(n%a==0)return true;
    return false;
}

int main(void)
{
    ll n;
    while(scanf("%lld",&n)==1){

        if(n<0)break;

        ll ans = -1;

        for(ll i=15;i>=1;i--){

            if(get(n , i)==true){

                ans = i;
                break;
            }
        }

        if(ans==-1)printf("%lld coconuts, no solution\n",n);
        else printf("%lld coconuts, %lld people and 1 monkey\n",n , ans);
    }
    return 0;
}
