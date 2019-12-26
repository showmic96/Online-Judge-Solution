// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n , c = 0;
    while(scanf("%lld",&n)==1){

        if(!n)break;
        int counter = 0;
        ll sum = 0 , temp = n;

        for(ll i=2;i*i<=temp;i++){

            if(n%i==0){

                counter++;
                ll temp = 1;
                while(n%i==0){

                    temp*=i;
                    n/=i;
                }

                sum+=temp;
            }
        }

        if(n>1){sum+=n;counter++;}

        if(counter==1)sum++;
        printf("Case %lld: %lld\n",++c , max(2LL ,sum));
    }
    return 0;
}
