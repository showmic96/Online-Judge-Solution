// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

double value(double c , double h)
{
    return 1.00*asin(c/(h+((c*c)/(4*h))))*(h+((c*c)/(4*h)));
}

int main(void)
{
    double x , y , z , L , c , h , s;
    while(cin >> x >> y >> z){
        if(x<0&&y<0&&z<0)break;
        c = x;

        s = (1+y*z)*x;

        int tt = 200;

        double hi = x , low = 0 , mid;
        //cout << s << " " << c << endl;
        while(tt--){

            mid = (hi+low)/2;

            if(value(c , mid)<s){

                low = mid;
            }

            else {

                hi = mid;
            }
        }

        printf("%.3f\n", mid);
    }
    return 0;
}
