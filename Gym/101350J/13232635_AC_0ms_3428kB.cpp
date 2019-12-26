// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        double l , x;
        scanf("%lf %lf",&l , &x);

        double t = acos(-1)*x/360;

        double ta = l*l*sin(t)*cos(t);

        t = l*l*t;

        printf("%.6f\n",t-ta);
    }
    return 0;
}
