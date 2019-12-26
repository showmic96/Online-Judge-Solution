// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t , c = 0;
    double l , w;
    while(scanf("%lf : %lf",&l , &w)==2){

        double r = sqrt((l/2)*(l/2)+(w/2)*(w/2));
        double theta = 2*atan(w/l);
        double s = r*theta;

        double ans2 = (w/(s+l)*200) , ans1 = (l/(s+l)*200);
        printf("Case %d: %.14f %.14f\n",++c , ans1 , ans2);
    }
    return 0;
}