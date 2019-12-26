// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        double a , b , c , d;
        scanf("%lf %lf %lf %lf",&a , &b , &c , &d);

        double s = (a+b+c+d)/2;

        double ans = sqrt((s-a)*(s-b)*(s-c)*(s-d));

        printf("%.2f\n",ans);
    }
    return 0;
}
