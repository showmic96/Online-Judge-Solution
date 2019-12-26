// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        double v1 , v2 , v3 , a1 , a2;

        scanf("%lf %lf %lf %lf %lf",&v1 , &v2 , &v3 , &a1 , &a2);
        
        double t1 = v1/a1;
        double t2 = v2/a2;
        
        double t = max(t1 , t2);

        double d = (v1*t1 - .5*a1*t1*t1) + (v2*t2 - .5*a2*t2*t2);

        printf("Case %d: %.14f %.14f\n",i+1 , d , t*v3);
    }
    return 0;
}
