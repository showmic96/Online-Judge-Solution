#include<stdio.h>

int main (void)
{
    int a , b, c, d ,e ,f;
    scanf("%d",&a);
    for (b=0;b<a;b++){
            if (b!=0) printf("\n");
        c=0;e=0;
        scanf("%d",&f);

        while(c<f){
            scanf("%d",&d);
            e=e+d;
            c=c+1;
        }

        printf("%d\n",e);
    }
    return 0;
}