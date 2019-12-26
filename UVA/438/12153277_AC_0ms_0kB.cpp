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

        printf("%.2f\n",2*acos(-1)*r);
    }

    return 0;
}
