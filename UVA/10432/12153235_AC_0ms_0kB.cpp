// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    double r , n;
    while(scanf("%lf %lf",&r , &n)==2){

        double ans = .5*n*r*r*sin(2*acos(-1)/n);
        printf("%.3f\n",ans);
    }

    return 0;
}
