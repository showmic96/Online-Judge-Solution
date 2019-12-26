// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double sum[1000005];

void pre()
{
    double s = 0;
    sum[0] = 0;
    for(int i=1;i<100000005;i++){

        s+=(1.00/(double)i);

        if(i%100==0){

            sum[i/100] = s;
        }
    }
}

int main(void)
{
    pre();

    int t , c = 0 ;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);

        double ans = sum[n/100];

        for(int i=(n/100)*100+1;i<=n;i++){

            ans+=(1.00/(double)i);
        }

        printf("Case %d: %.14f\n",++c , ans);

    }
    return 0;
}
