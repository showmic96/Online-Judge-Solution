#include<stdio.h>

int main ()
{
    int a , b, c, d ,e ,f;
    while (scanf("%d",&a)!=EOF){
        c=0;e=0;

        while(c<a){
            scanf("%d",&d);
            e=e+d;
            c=c+1;
        }
        printf("%d\n",e);
    }
    return 0;
}
