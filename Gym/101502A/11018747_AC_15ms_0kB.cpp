#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        double x , y;
        scanf("%lf %lf",&y , &x);

        double ans =1.00*(y)/(1.00+(x/100.00));

        printf("%.0f\n",ans);
    }
    return 0;
}
