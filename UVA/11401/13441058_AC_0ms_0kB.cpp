// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans[1000005];

int main(void)
{
    ll now = 4 , dif = 2;
    ans[3] = 0;
    ans[4] = 1;
    ans[5] = 3;
    ans[6] = 7;
    for(int i=7;i<=1000000;i++){

        if(i%2==0)dif++;
        now+=dif;
        ans[i] = ans[i-1]+now;
    }
    int n;
    while(scanf("%d",&n)==1){

        if(n<3)break;
        printf("%lld\n",ans[n]);
    }
    return 0;
}
