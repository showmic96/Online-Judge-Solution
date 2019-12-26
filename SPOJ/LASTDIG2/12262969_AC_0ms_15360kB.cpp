// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll BM(ll a , ll b , ll M)
{
    if(b==0)return 1%M;
    ll x = BM(a , b/2 , M);
    x = (x*x)%M;
    if(b%2==1)x = (x*a)%M;

    return x;
}

char x[10005];

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%s",&x);
        ll m;
        scanf("%lld",&m);

        printf("%lld\n",BM(x[strlen(x)-1]-'0' , m , 10));

    }
    return 0;
}
