#include<stdio.h>
int main(void)
{
    int a ,b[13],c ,d ,e , f;
    scanf("%d",&a);
    for (c=0;c<a;c++){
            e=0;
        for (d=0 ; d<13;d++){
            scanf("%d",&b[d]);
            if (b[d]==0) e=1;
        }
    if (e==0) printf("Set #%d: Yes\n",c+1);
    if (e!=0) printf("Set #%d: No\n",c+1);
    }

    return 0;
}