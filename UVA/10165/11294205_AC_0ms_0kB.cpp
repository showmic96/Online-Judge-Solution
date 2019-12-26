// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        if(!n)break;

        ll ans = 0;

        for(int i=0;i<n;i++){

            ll in;
            scanf("%d",&in);
            ans^=in;
        }

        if(ans>0)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
