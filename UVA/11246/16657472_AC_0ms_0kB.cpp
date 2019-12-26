// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        ll n , k;
        scanf("%lld %lld",&n , &k);

        ll now = k , counter = n;
        if(k>n){

            printf("%lld\n",n);
            continue;
        }

        for(int i=0;;i++){

            if(i%2==1)counter+=n/now;
            else counter-=n/now;
            now*=k;
            if(now>n)break;
        }
        printf("%lld\n",counter);
    }
    return 0;
}
