// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double f(double t , double n , double c)
{

    return t*(c-n*t);
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        double l , w;

        scanf("%lf %lf",&l, &w);

        double left = 0 , right = 1e15;
        ll ans = 0 , mx = 0;

        for(int i=0;i<400;i++){

            double l1 = (right+2*left)/3;
            double l2 = (2*right+left)/3;

            if(f(l1 , l , w)>f(l2 , l , w))right = l2 , ans = right;
            else left = l1 , ans = right;
        }


        for(ll i = left - 10;i<left+10;i++){

            if(i<0)continue;

            ll temp = i*(w-l*i);

            if(temp>mx){

                mx = temp;
                ans = i;
            }
        }

        if(l==0||w==0)ans = 0;

        printf("Case %d: %lld\n",++c ,ans);
    }
    return 0;
}
