// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        double d , v;
        scanf("%lf %lf",&d , &v);

        double r = sqrt((3*v*282)/(acos(-1)*d*7)) * 2;

        printf("Case %d: %.3f\n",++c , r*2);
    }
    return 0;
}
