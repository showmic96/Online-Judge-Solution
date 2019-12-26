#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    double a , b , c , d , e , f , x , y;

    while(cin >> a >> b >> c >> d >> e >> f){
        x = y = 0;
        x = (f*b-c*e)/(b*d-a*e);
        y = (c-a*x)/b;

        if(x==-0)x=0;
        if(y==-1)y=0;

        printf("%.3lf %.3lf\n",x,y);
    }
    return 0;
}
