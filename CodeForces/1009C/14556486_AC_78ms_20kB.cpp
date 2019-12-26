// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n , m;
    scanf("%d %d",&n , &m);

    ll sum = 0;
    for(int i=0;i<m;i++){

        double in1 , in2;
        scanf("%lf %lf",&in1 , &in2);
        sum+=(in1*(ll)n);

        if(in2>=0){

            ll t = n;
            ll temp = t*(t-1);
            temp/=2;
            temp*=in2;
            sum+=temp;
        }
        else{

            ll dd = n/2;
            ll t1 = dd;
            ll t2 = n-dd;

            ll temp = t1*(t1+1)/2;
            temp*=in2;
            sum+=temp;

            temp = t2*(t2-1)/2;
            temp*=in2;
            sum+=temp;
        }
    }

    printf("%.14f\n",(double)sum/(double)n);

    return 0;
}