// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

double eps = 1e-9;
double a1 ,a2 ,a3 , b1 , b2 , b3 , c1 , c2 , c3;

double dis(double t)
{
    double x1 = a1+t*(b1-a1);
    double x2 = a2+t*(b2-a2);
    double x3 = a3+t*(b3-a3);

    double dis = sqrt((x1-c1)*(x1-c1)+(x2-c2)*(x2-c2)+(x3-c3)*(x3-c3));

    return dis;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%lf %lf %lf",&a1 , &a2 , &a3);
        scanf("%lf %lf %lf",&b1 , &b2 , &b3);
        scanf("%lf %lf %lf",&c1 , &c2 , &c3);

        int t = 200;
        double l = 0 , r = 1;

        while(t--){

            double m1 = (2.00*l+r)/3.00;
            double m2 = (l+2.00*r)/3.00;

            if(dis(m1)<dis(m2))r = m2;
            else l = m1;
        }

        printf("Case %d: %.14lf\n",++c , dis(l)+eps);
    }
    return 0;
}
