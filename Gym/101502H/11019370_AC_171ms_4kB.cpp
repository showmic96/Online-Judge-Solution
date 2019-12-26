#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        double a , b, c , d;
        scanf("%lf %lf %lf %lf",&a , &b , &c , &d);

        double t1 = b*log10(a);
        double t2 = d*log10(c);

        if(t1>t2)printf(">\n");
        else printf("<\n");
    }
    return 0;
}
