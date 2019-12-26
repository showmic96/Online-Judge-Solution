// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

double ax , ay , bx , by , cx , cy , dx , dy;

double f(double x)
{
    double ex = ax+x*(bx-ax);
    double ey = ay+x*(by-ay);

    double fx = cx+x*(dx-cx);
    double fy = cy+x*(dy-cy);

    return (double)sqrt((fx-ex)*(fx-ex)+(fy-ey)*(fy-ey));
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&ax , &ay , &bx, &by , &cx , &cy , &dx , &dy);

        int tt = 200;

        double l = 0.0 , r = 1.0;

        while(tt--){

            double l1 = (2.0*l+r)/3.0;
            double l2 = (l+2.0*r)/3.0;

            if(f(l1)<f(l2))r = l2;
            else l = l1;
        }

        double ans = f((l+r)/2.0);

        printf("Case %d: %.14f\n",++c , ans);
    }
    return 0;
}
