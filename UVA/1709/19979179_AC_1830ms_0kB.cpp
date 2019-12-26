// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    double p , a , b , c , d;
    int n;
    while(scanf("%lf %lf %lf %lf %lf %d",&p , &a , &b , &c , &d , &n)==6){
        double ans = -1e38 , ret = 0;
        for(int i=1;i<=n;i++){
            double temp = p*(sin(a*(double)i+b)+
                             cos(c*(double)i+d)+2);
            ret = max(ret , ans-temp);
            ans = max(ans , temp);
        }
        printf("%.14f\n",ret);
    }
    return 0;
}
