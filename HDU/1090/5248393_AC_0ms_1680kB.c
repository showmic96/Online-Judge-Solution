#include<stdio.h>

int main ()
{
    int a , b , c, d ,e;
    scanf("%d",&a);
    for (b=1 ; b<=a;b++){
        scanf("%d %d",&d ,&c);
        printf("%d\n",c+d);
    }
    return 0;
}
