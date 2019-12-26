#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double a , b;

double f(double now)
{
    double temp = a*sin(now) + b*cos(now);
    return temp;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%lf %lf",&a , &b);

        double l = 2*acos(-1) , r = 0.0;

        for(int i=0;i<200;i++){

            double l1 = (l*2+r)/3;
            double l2 = (l+r*2)/3;

            if(f(l1)>f(l2))r  = l2;else l = l1;
        }

        double x = l;
        printf("%.2f %.2f\n",x , f(x));
    }
    return 0;
}
