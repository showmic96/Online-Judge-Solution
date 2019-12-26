// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        if(!n)break;
        for(int i=0;i<n;i++){
            int a , b , c, d , e;
            scanf("%d %d %d %d %d",&a , &b , &c , &d , &e);
            if(a<=127)a = 1;
            else a = 0;

            if(b<=127)b = 1;
            else b = 0;

            if(c<=127)c = 1;
            else c = 0;

            if(d<=127)d = 1;
            else d = 0;

            if(e<=127)e = 1;
            else e = 0;

            if(a+b+c+d+e==1){

                if(a==1)printf("A\n");
                if(b==1)printf("B\n");
                if(c==1)printf("C\n");
                if(d==1)printf("D\n");
                if(e==1)printf("E\n");
            }

            else printf("*\n");
        }
    }
    return 0;
}
