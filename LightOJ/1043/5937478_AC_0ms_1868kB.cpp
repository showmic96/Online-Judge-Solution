#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(void)
{
    ll a;
    cin >> a;
    for(ll b=0;b<a;b++){
        double c , d , e , f;
        cin >> c >> d >> e >>f;
        double s = 0.5*(c+d+e);
        double areaTriangle =sqrt(s*(s-c)*(s-d)*(s-e));
        double aretriangle = f/(f+1)*areaTriangle;
        double x = pow((aretriangle*aretriangle)/(s*(s-c)*(s-d)*(s-e)),0.25);
        printf("Case %lld: %.7f\n",b+1,c*x);
    }
    return 0;
}
