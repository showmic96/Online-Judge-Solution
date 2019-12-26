// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t , tc = 0;
    scanf("%d",&t);
    while(t--){

        double a , b , c , d;
        scanf("%lf %lf %lf %lf",&a , &b , &c , &d);

        if(c>a)swap(a , c);

        double s = 0.5*(a-c+b+d);
        double area = sqrt(s*(s-d)*(s-b)*(s-a+c));
        double h = (area*2.0)/(a-c);
        double area_final = (c+a)/2.0;
        area_final*=h;

        printf("Case %d: %.14f\n",++tc , area_final);

    }
    return 0;
}
