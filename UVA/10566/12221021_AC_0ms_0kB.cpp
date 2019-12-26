#include<bits/stdc++.h>
using namespace std;

double in1 , in2 , in3 , h1 , h2;
double hi , low , mid;

double result(double a)
{
    h1 = sqrt((in1*in1)-(mid*mid));
    h2 = sqrt((in2*in2)-(mid*mid));

    return (1.00*(h1*h2)/(h1+h2));

}

int main(void)
{

    while(scanf("%lf%lf%lf",&in1 ,&in2 , &in3)==3){

        int counter = 1000;

        hi = min(in1 ,in2);

        low = 0.0;

        while(counter--){

            mid = (hi+low)/2.0;

            if(result(mid)<in3){

                hi = mid;
            }
            else{

                low = mid;
            }
        }

        printf("%.3f\n",mid);
    }

    return 0;
}
