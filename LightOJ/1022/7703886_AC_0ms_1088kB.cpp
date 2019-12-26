#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)
int main()
{
    int i,t;
    double r,sqr,cir,left;
    while(scanf("%d\n",&t)!=EOF)
    {
        for(i=1;i<=t;i++)

        {
            scanf("%lf",&r);
            sqr=4.0*r*r;
            cir=pi*r*r;
            left=sqr-cir;
            printf("Case %d: %.2lf\n",i,left);
        }

    }

    return 0;
}
