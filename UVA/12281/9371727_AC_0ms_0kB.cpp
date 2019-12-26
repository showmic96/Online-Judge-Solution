// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fib[67];

void pre_cal()
{
    fib[0] = 0;
    fib[1] = 1;

    for(int i=2;i<67;i++){

        fib[i] = fib[i-1] + fib[i-2];
    }
}


int main(void)
{
    pre_cal();
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);

        ll ans = 1;

        for(int i=0;i<n;i++){

            ll in , counter = 0;
            scanf("%lld",&in);

            for(int i=66;i>=0;i--){

                while(in-fib[i]>=0&&in>0){

                    in-=fib[i];
                    counter++;
                }
            }

            ans*=counter;
        }

        printf("Case %d: %lld\n",++c, ans);
    }

    return 0;
}
