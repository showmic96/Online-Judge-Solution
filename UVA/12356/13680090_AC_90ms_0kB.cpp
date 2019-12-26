// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int l[100005] , r[100005];

int main(void)
{
    int s , b;
    while(scanf("%d %d",&s , &b)==2){

        if(!s&&!b)break;

        for(int i=1;i<=s;i++){

            l[i] = i-1;
            r[i] = i+1;
        }

        l[1] = -1;
        r[s] = -1;

        while(b--){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);

            l[r[in2]] = l[in1];
            r[l[in1]] = r[in2];

            if(l[in1]==-1)printf("*");
            else printf("%d",l[in1]);

            if(r[in2]==-1)printf(" *\n");
            else printf(" %d\n",r[in2]);
        }
        printf("-\n");
    }
    return 0;
}
