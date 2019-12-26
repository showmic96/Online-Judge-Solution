// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double value(double c , double x , double y , double d)
{

    return (double)((1.00/c)-(1.00/sqrt(x*x-d*d))-(1.00/sqrt(y*y-d*d)));
}

int main(void)
{
    //freopen("input.txt","r",stdin);
    double x , y , c , d , hi , low;
    int t;
    cin >> t;

    for(int i=0;i<t;i++){

        cin >> x >> y >> c;
        hi = min(x , y);
        low = 0.0;
        int loop = 1e6;

        while(loop--){

            d = (double)((hi+low)/2.00);

            if(value(c , x , y, d)<=0.00){

                hi = d;
            }

            else low = d;
        }

        printf("Case %d: %.14lf\n", i+1 , d);

    }
    return 0;
}
