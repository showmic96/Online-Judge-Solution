#include<stdio.h>

int main ()
{
    int a , b, c, d ,e ,f;
    scanf("%d",&f);
    for(e=0;e<f;e++){
        d=0;b=0;
        scanf("%d",&a);

        while (b<a){
        scanf("%d",&c);
        d=d+c;
        b=b+1;
    }
    printf("%d\n",d);
    }
    return 0;
}