// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t--){

        ll n , m;
        scanf("%lld %lld",&n, &m);

        ll counter = 0;

        while(true){

            if(n==m){n = 0;counter++;break;}

            counter+=n/m;
            n = n/m + n%m;

            if(n<m)break;
        }

        if(n!=0)printf("cannot do this\n");
        else printf("%lld\n",counter);
    }

    return 0;
}
