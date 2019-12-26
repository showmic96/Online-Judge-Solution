// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char temp[33];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll n;
        double cur , counter = 0;

        scanf("%lf %lld",&cur , &n);
        counter = cur;
        for(int i=0;i<n;i++){

            double in;
            scanf("%lf",&in);
            if(in<0){

                in = -in;
                in = 100.00/in;
            }
            else in = in/100.00;

            sprintf(temp , "%.3f" , in);
            sscanf(temp , "%lf",&in);

            in = in*counter;

            counter+=ceil(in);
        }

        ll value = counter;

        printf("%d $",++c);

        if(value<1000)printf("%lld.00\n",value);
        else{

            if(value>=1000000)printf("1,000,000.00\n");
            else{

                ll t1 = value%1000;
                ll t2 = value/1000;

                printf("%lld,%03lld.00\n",t2 , t1);
            }
        }
    }

    return 0;
}
