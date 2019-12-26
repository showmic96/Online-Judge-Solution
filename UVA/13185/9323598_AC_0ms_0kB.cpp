// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll value[123456];

void seive()
{
    memset(value , 0 , sizeof(value));
    ll lim = 123456;

    for(ll i=2;i<lim;i++){

        for(ll j=2;i*j<123456;j++){

            value[i*j]+=i;
        }
    }
}

int main(void)
{
    seive();
    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        if(value[n]+1==n)printf("perfect\n");
        else if(value[n]+1>n)printf("abundant\n");
        else printf("deficient\n");
    }
    return 0;
}
