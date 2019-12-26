// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int ans[5005];
int dv[1005];

void pre()
{
    memset(ans , -1 , sizeof(ans));
    memset(dv , 0 , sizeof(dv));

    for(int i=1;i<1005;i++){

        for(int j=i;j<1005;j+=i){

            dv[j]+=i;
        }
    }

    for(int i=0;i<1005;i++){

        ans[dv[i]] = i;
    }
}

int main(void)
{
    pre();
    int c = 0 , n;
    while(scanf("%d",&n)==1){

        if(n==0)break;
        printf("Case %d: %d\n",++c , ans[n]);
    }
    return 0;
}
