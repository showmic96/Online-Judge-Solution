// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

double value(double r_t , double p , double r1 , double r2 , double h)
{
    double area1 = acos(-1)*(p/3)*(r_t*r2 + r_t*r_t + r2*r2);
    double area2 = acos(-1)*((h-p)/3)*(r_t*r_t + r_t*r1 + r1*r1);

    return area1 + area2;
}

int main(void)
{
    int t;
    cin >> t;

    for(int i=0;i<t;i++){

        double r1 , r2 , h , p;
        cin >> r1 >> r2 >> h >> p;

        double hi = r1 , low = 0 , mid , area = (acos(-1)*h/3)*(r1*r2 + r1*r1 + r2*r2);

        int c = 1000;

        while(c--){

            mid = (hi+low)/2;

            if(value(mid , p , r1 , r2 , h)>area){

                hi = mid;
            }
            else low = mid;
        }

        double ans = acos(-1)*(p/3)*(mid*r2 + mid*mid + r2*r2);

        printf("Case %d: %.14f\n",i+1,ans);
    }
    return 0;
}
