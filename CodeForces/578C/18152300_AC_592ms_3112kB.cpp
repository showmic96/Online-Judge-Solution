// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<double>v;
int n;

double f(double x)
{
    double mx = 0 , counter = 0;
    for(int i=0;i<n;i++){

        counter+=v[i]-x;
        if(counter>0)counter = 0;
        mx = max(mx , abs(counter));
    }
    counter = 0;
    for(int i=0;i<n;i++){

        counter+=v[i]-x;
        if(counter<0)counter = 0;
        mx = max(mx , abs(counter));
    }
    return mx;
}

int main(void)
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        double in;
        scanf("%lf",&in);
        v.push_back(in);
    }

    double l = 20000, r = -20000;

    for(int i=0; i<200; i++) {
      double l1 = (l*2+r)/3;
      double l2 = (l+2*r)/3;
      if(f(l1) < f(l2)) r = l2; else l = l1;
    }

    printf("%.14f\n",f(l));

    return 0;
}
