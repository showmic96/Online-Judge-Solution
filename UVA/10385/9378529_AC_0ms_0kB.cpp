// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

double length;
vector<double>v1 , v2;
int n;

double value(double d1 , double d2)
{

    double x1 = 1.00*(d1/v1[n-1]) + 1.00*(d2/v2[n-1]);

    double x2 = 1e25;

    for(int i=0;i<n-1;i++){

        double temp = d1/v1[i] + d2/v2[i];
        x2 = min(x2 , temp);
    }

    return x2 - x1;
}

int main(void)
{
    while(scanf("%lf",&length)==1){

        scanf("%d",&n);
        v1.clear();
        v2.clear();

        for(int i=0;i<n;i++){

            double in1 , in2;
            scanf("%lf %lf",&in1 , &in2);

            v1.push_back(in1);
            v2.push_back(in2);
        }

        int t = 300;

        double l = 0.00 , r = length , ans = -100;

        while(t--){

            double l1 = 1.00*(l*2+r)/3.00;
            double l2 = 1.00*(l+2*r)/3.00;

            //cout << l1 << " " << l2 << endl;

            if(value(l1 , length-l1) > value(l2 , length-l2)){ r = l2;}

            else l = l1;

        }

        l = (l+r)/2;

        double time = (value(l , length -l) * 3600);
        //cout << time << endl;

        if(time<0){

            printf("The cheater cannot win.\n");
        }

        else{

            printf("The cheater can win by %.0f seconds with r = %.2fkm and k = %.2fkm.\n",time , l , length-l);
        }
    }

    return 0;
}
