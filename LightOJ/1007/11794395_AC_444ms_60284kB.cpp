// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 5e6 + 9;

int phi[MAX+9];

unsigned long long sum[MAX+9];

void seive()
{
    for(int i=0;i<=MAX;i++)phi[i] = i;

    phi[1] = 1;

    for(int i=2;i<=MAX;i++){

        if(phi[i]==i){

            for(int j=i;j<=MAX;j+=i){

                phi[j] = phi[j]/i*(i-1);
            }
        }
    }

    sum[0] = 0;

    for(int i=1;i<=MAX;i++){

        sum[i] = sum[i-1]+(ll)((ll)phi[i]*(ll)phi[i]);
    }
}

int main(void)
{
    seive();
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);

        printf("Case %d: %llu\n",++c , sum[in2]-sum[in1-1]);

    }
    return 0;
}
