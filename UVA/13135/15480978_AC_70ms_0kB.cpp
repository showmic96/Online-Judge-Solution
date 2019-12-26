// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int bs[50000000+10];

int main(void)
{
    memset(bs , 0 , sizeof(bs));

    for(ll i=1;(i+1LL)*(i+2LL)/2LL<=50000005;i++){

        bs[(i+1LL)*(i+2LL)/2LL] = i;
    }

    int t;
    scanf("%d",&t);
    while(t--){

        int in;
        scanf("%d",&in);

        if(bs[in]!=0)printf("%d\n",bs[in]);
        else printf("No solution\n");
    }

    return 0;
}
