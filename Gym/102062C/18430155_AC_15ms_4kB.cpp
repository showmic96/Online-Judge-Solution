// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        double r;
        scanf("%lf",&r);
        double r1 = sqrt(2.00*r*r)/2.00;
        double af = sqrt(2.00*r1*r1);
        double r2 = af/2.00;
        double area1 = (acos(-1)*r2*r2)/2.00;
        double area2 = (acos(-1)*r1*r1)/4.00-0.5*r1*r1;
        double tot = area1-area2;
        printf("Case %d: %.4f\n",++c , tot);
    }
    return 0;
}
