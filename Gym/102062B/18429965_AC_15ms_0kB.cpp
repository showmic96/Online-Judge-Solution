// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        double m , d;
        scanf("%lf %lf",&m , &d);
        double v = m/d;
        double temp = v*3.00/(4.00*acos(-1));
        double r = pow(temp,1.00/3.00);
        double area = 4.00*acos(-1)*r*r;
        printf("Case %d: %.4f\n",++c,area);
    }
    return 0;
}
