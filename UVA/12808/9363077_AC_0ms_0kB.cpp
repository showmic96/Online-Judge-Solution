// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        double l , d , h , v;
        scanf("%lf %lf %lf %lf",&l , &d , &h , &v);
        l/=1000;
        d/=1000;
        h/=1000;
        v/=1000;

        double t = sqrt((2*h)/9.81);

        double dis = t*v;

        if(abs(d-dis)<=0.5||abs(l+d-dis)<=0.5)printf("EDGE\n");
        else if(dis<d||dis>l+d)printf("FLOOR\n");
        else printf("POOL\n");
    }
    return 0;
}
