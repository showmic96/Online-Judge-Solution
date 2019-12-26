// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double dp[11][111];
int k , n;

double f(int last , int i)
{
    if(i==n)return 1;
    if(dp[last][i]!=-1)return dp[last][i];

    double value = f(last , i+1);

    if(last+1<=k)value+=f(last+1 , i+1);
    if(last-1>=0)value+=f(last-1 , i+1);

    return dp[last][i] = value;
}

int main(void)
{
    while(scanf("%d %d",&k , &n)==2){

        for(int i=0;i<11;i++){

            for(int j=0;j<111;j++){

                dp[i][j] = -1;
            }
        }

        double ans = 0;

        for(int i=0;i<=k;i++){

            ans+=f(i , 1);
        }
        ans/=pow(k+1 , n);

        printf("%.5f\n",ans*100);
    }
    return 0;
}
