// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

double value(double c , double h)
{
    return 1.00*asin(c/(h+((c*c)/(4*h))))*(h+((c*c)/(4*h)));
}

int main(void)
{
    int t;
    cin >> t;

    for(int i=0;i<t;i++){

        double x , y , z , L , c , h , s;

        cin >> x >> y >> z;

        c = x;

        s = (1+y*z)*x;

        int tt = 1e4;

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

        printf("Case %d: %.14lf\n",i+1 , mid);
    }
    return 0;
}
