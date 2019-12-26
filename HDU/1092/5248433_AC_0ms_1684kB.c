#include<stdio.h>

int main ()
{
    int a , b, c, d ;
    while (scanf("%d",&a)!=EOF){
        if (a==0) break ;
        d=0;b=0;
        while (b<a){
        scanf("%d",&c);
        d=d+c;
        b=b+1;
    }
    printf("%d\n",d);
    }
    return 0;
}
