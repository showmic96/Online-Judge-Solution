// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        
        double a , b , d;
        scanf("%lf %lf %lf",&a , &b , &d);
        double r = d/2;
        double l = d/sqrt(2);
        
        double a1 = acos(-1)*r*r;
        double a2 = l*l;
        double a3 = acos(-1)*(l/2)*(l/2);
        
        printf("%.14f\n",2*a3-(a1-a2));
    }
    return 0;
}