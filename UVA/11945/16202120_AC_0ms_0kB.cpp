// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);

    int t , c = 0;
    cin >> t;

    while(t--){

        double sum = 0;
        for(int i=0;i<12;i++){

            double in;
            cin >> in;
            sum+=in;
        }

        sum/=12;

        ll now = sum;
        ll temp = now%1000;

        sum-=now;
        now/=1000;

        printf("%d $",++c);
        if(now>0)printf("%lld,",now);
        printf("%.2f\n",(double)(sum+temp));
    }

    return 0;
}
