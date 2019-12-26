// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

double dis(double x1 , double y1 , double x2 , double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        double x1 , x2 , y1 , y2 , r1 , r2;
        scanf("%lf %lf %lf %lf %lf %lf",&x1 , &y1 , &r1 , &x2 , &y2 , &r2);

        double d = dis(x1 , y1 , x2 , y2);

        if(d>=r1+r2)printf("Case %d: 0\n",++c);
        else if(r1>=d+r2)printf("Case %d: %.14f\n",++c , acos(-1)*r2*r2);
        else if(r2>=d+r1)printf("Case %d: %.14f\n",++c , acos(-1)*r1*r1);
        else{

            double th1 = acos((r1*r1+d*d-r2*r2)/(2.00*r1*d));
            double th2 = acos((r2*r2+d*d-r1*r1)/(2.00*r2*d));

            double area = .5*r1*r1*(2.00*th1)-.5*r1*r1*sin(2.00*th1)-.5*r2*r2*sin(2.00*th2)+.5*r2*r2*(2.00*th2);

            printf("Case %d: %.14f\n",++c , area);
        }
    }
    return 0;
}
