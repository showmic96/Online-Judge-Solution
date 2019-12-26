// In the name of Allah the most Merciful .

#include<bits/stdc++.h>

using namespace std;

#define pi acos(-1)

int main(void)
{
    int t;
    cin >> t;

    double r1 , r2 , r3 , a , b , c , s , s_temp, area , area1 , area2 , area3 , t1 , t2 , t3;

    for(int i=0;i<t;i++){

        cin >> r1 >> r2 >> r3;

        a = r1+r2;
        b = r2+r3;
        c = r3+r1;

        s = 2.00*(r1 + r2 + r3);
        s_temp = r1+r2+r3;

        area = 1.00*sqrt(s_temp*(s_temp-r1-r2)*(s_temp-r2-r3)*(s_temp-r3-r1));

        t1 = 1.00*acos((b*b+c*c-a*a)/(2*b*c));
        t2 = 1.00*acos((a*a+c*c-b*b)/(2*a*c));
        t3 = 1.00*acos((b*b+a*a-c*c)/(2*b*a));

        area1 = 1.00*r1*r1*(t2/2);
        area2 = 1.00*r2*r2*(t3/2);
        area3 = 1.00*r3*r3*(t1/2);

        printf("Case %d: %.10lf\n",i+1 , area - area1 - area2 - area3);
    }

    return 0;
}
