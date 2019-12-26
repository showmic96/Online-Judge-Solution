// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll w , n;
    while(scanf("%lld",&w)==1){

        scanf("%lld",&n);

        ll sum = 0;
        for(int i=0;i<n;i++){

            ll in1 , in2;
            scanf("%lld %lld",&in1 , &in2);
            sum+=in1*in2;
        }
        printf("%lld\n",sum/w);
    }
    return 0;
}
