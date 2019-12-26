// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    double a , b , c;
    while(cin >> a >> b >> c){

        double s = a + b + c;
        s/=2;

        double area = sqrt(s*(s-a)*(s-b)*(s-c));

        double c_r = (a*b*c)/(4*area);

        double c_area = (acos(-1)*c_r*c_r) - area;

        double c2_r = sqrt((s-a)*(s-b)*(s-c)/s);

        double c2_area = (acos(-1)*c2_r*c2_r);

        area-=c2_area;

        printf("%.4f %.4f %.4f\n",c_area , area , c2_area);
    }

    return 0;
}
