// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ar[(1<<15)+10];
ll sum[(1<<15)+10];

bool Check(int n , int pos)
{
    return n&(1<<pos);
}
int Set(int n , int pos)
{
    return n|(1<<pos);
}
int Reset(int n , int pos)
{
    return n&~(1<<pos);
}

int main(void)
{
    ll n;
    while(scanf("%lld",&n)==1){

        for(int i=0;i<(1<<n);i++){

            scanf("%lld",&ar[i]);
        }

        for(int i=0;i<(1<<n);i++){

            ll counter = 0 , now = i;

            for(int j=0;j<n;j++){

                if(Check(i , j)==true)now = Reset(i , j);
                else now = Set(i , j);
                counter+=ar[now];
            }
            sum[i] = counter;
        }

        ll ans = 0;

        for(int i=0;i<(1<<n);i++){

            ll counter = 0 , now = i;

            for(int j=0;j<n;j++){

                if(Check(i , j)==true)now = Reset(i , j);
                else now = Set(i , j);
                ans = max(ans , sum[i]+sum[now]);
            }
        }

        printf("%lld\n",ans);

    }
    return 0;
}
