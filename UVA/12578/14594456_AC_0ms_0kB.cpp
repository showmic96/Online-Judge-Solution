#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        double l;
        scanf("%lf",&l);

        double w = 6.0/10.0*l;
        double r  = 1.0/5.0*l;

        double a1 = l*w;
        double a2 = acos(-1)*r*r;
        printf("%.2f %.2f\n",a2 , a1-a2);

    }
    return 0;
}
