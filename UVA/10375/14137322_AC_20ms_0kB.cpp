// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n1 , c1 , n2 , c2;

    while(scanf("%d %d %d %d",&n1 , &c1 , &n2 , &c2)==4){

        long double ans = 1;

        for(int i=0;i<100005;i++){

            long double temp;

            if(n1-i>c1){

                temp = n1-i;
                ans*=temp;
            }
            if(n2-i>c2){

                temp = n2-i;
                ans/=temp;
            }
            if(n1-c1-i>=1){

                temp = n1-c1-i;
                ans/=temp;
            }
            if(n2-c2-i>=1){

                temp = n2-c2-i;
                ans*=temp;
            }
        }
        double a = ans;
        printf("%.5lf\n",a);
    }

    return 0;
}
