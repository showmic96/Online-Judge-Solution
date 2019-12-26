// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double f(double x , double l , double w)
{
    if(l-2*x<0)return 0;
    if(w-2*x<0)return 0;

    return x*(l-2*x)*(w-2*x);
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        double l , w;

        scanf("%lf %lf",&l, &w);

        double left = 0 , right = min(l , w);

        for(int i=0;i<200;i++){

            double l1 = (right+2*left)/3;
            double l2 = (2*right+left)/3;

            if(f(l1 , l , w)>f(l2 , l , w))right = l2;
            else left = l1;
        }

        double x = left;
        double volume = (l-2*x)*(w-2*x)*x;

        printf("Case %d: %.14f\n",++c , volume);
    }
    return 0;
}
