// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

double p , q , r , s , t , u;

double f(double x)
{
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

int main(void)
{
    while(scanf("%lf %lf %lf %lf %lf %lf", &p , &q , &r , &s , &t , &u)==6){

        if(f(0)*f(1)>0)printf("No solution\n");
        else{

            double hi = 1 , low = 0 , mid , ans = 0;
            int t = 2000;

            while(t--){

                mid = (hi+low)/2;

                double temp = f(mid);

                if(temp>=-0.0000001&&temp<=0.0000001){

                    ans = mid;
                }

                if(f(mid)<=0){

                    hi = mid-1;

                }

                else{

                    low = mid+1;
                }
            }

            printf("%.4f\n",abs(ans));
        }
    }
    return 0;
}
