// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    double v , v0;
    vector<double>vv;

    while(scanf("%lf %lf",&v , &v0)==2){

        if(v==0&&v0==0)break;
        vv.clear();

        double ans = 0;
        int mx = 0;

        for(int i=1;i<=v;i++){

            double t = i;
            double temp = v/t;
            if(temp<=v0)break;

            double now = 0.3*sqrt(temp-v0)*t;

            if(abs(now-ans)<0.000001){

                vv.push_back(now);
                ans = now;
            }

            if(now>ans){

                vv.clear();
                mx = i;
                ans = now;
                vv.push_back(now);
            }
        }

        if(vv.size()==1)printf("%d\n",mx);
        else printf("0\n");
    }
    return 0;
}
