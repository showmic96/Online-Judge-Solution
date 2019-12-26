// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    double x1 , y1 , x2 , y2 , x3 , y3;
    while(scanf("%lf %lf %lf %lf %lf %lf",&x1 ,&y1 , &x2 , &y2 , &x3 , &y3)==6){

        double a = x1*(y2-y3) - y1*(x2-x3) + x2*y3 - x3*y2;
        double b = (x1*x1+y1*y1)*(y3-y2) + (x2*x2+y2*y2)*(y1-y3) + (x3*x3+y3*y3)*(y2-y1);
        double c = (x1*x1+y1*y1)*(x2-x3) + (x2*x2+y2*y2)*(x3-x1) + (x3*x3+y3*y3)*(x1-x2);
        double d = (x1*x1+y1*y1)*(y2*x3-y3*x2) + (x2*x2+y2*y2)*(x1*y3-x3*y1) + (x3*x3+y3*y3)*(x2*y1-x1*y2);

        double r = sqrt((b*b+c*c-4*a*d)/(4*a*a));

        double c1 = -(b/(2*a));
        double c2 = -(c/(2*a));

        char s1 , s2 , s3 , s4;

        if(c1>0)s1 = '-';
        else s1 = '+';

        if(c2>0)s2 = '-';
        else s2 = '+';

        printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n",s1 ,fabs(c1) , s2 , fabs(c2) , r);

        r = -r*r+c1*c1+c2*c2;
        c1 = 2*c1;
        c2 = 2*c2;

        if(c1<=0)s1 = '+';
        else s1 = '-';

        if(c2<=0)s2 = '+';
        else s2 = '-';

        if(r>=0)s3 = '+';
        else s3 = '-';

        printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n",s1 , fabs(c1) , s2 , fabs(c2) , s3 , fabs(r));

        printf("\n");
    }

    return 0;
}
