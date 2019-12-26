// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int ar[100005];

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        if(!n)break;

        memset(ar , 0 , sizeof(ar));
        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            ar[max(0 , in1-in2)]+=1;
            ar[in1+in2+1]-=1;
        }

        int ans = 0;

        for(int i=1;i<100005;i++){

            ar[i] = ar[i-1]+ar[i];
            ans = max(ar[i] , ans);
        }

        printf("%d\n",ans);
    }
    return 0;
}
