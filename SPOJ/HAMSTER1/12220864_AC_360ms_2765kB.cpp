// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

double k1 , k2 , v;

double f(double t)
{
    return k2*v*v*sin(t)*sin(t)/20.0+k1*v*v*sin(2*t)/10.0;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%lf %lf %lf",&v , &k1 , &k2);

        double low = 0 , hi = acos(-1)/2 , l , r , ans;
        int c = 200;
        while(c--){

            l = (hi+2*low)/3;
            r = (hi*2+low)/3;

            if(f(l)>f(r)){
                hi = r;
            }
            else low = l;
        }

        printf("%.3f %.3f\n",low , f(low));
    }
    return 0;
}
