#include<stdio.h>

int main ()
{
    int a ,f;
    double b , c=0,d,e;

    scanf("%d",&a);
    for (f=0;f<a;f++){
        scanf("%lf",&b);
        c=2 * acos (0.0)*b*b;
        d = 4*b*b ;
        e=d-c;
        printf("Case %d: %.2lf\n",f+1 ,e);
    }
    return 0;
}