// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int n , m;
double dp[21][(1<<20)+5];
double ar[21][21];
double eps = 1e-9;

int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

double f(int i , int mask)
{
    if(i==n){

        return 0;
    }

    if(dp[i][mask]!=-1)return dp[i][mask];

    double value = 1e19;

    for(int j=0;j<m;j++){

        if(Check(mask , j)==false){

            value = min(value , f(i+1 , Set(mask , j))+ar[i][j]);
        }
    }

    return dp[i][mask] = value;
}

int main(void)
{
    while(scanf("%d %d",&n, &m)==2){

        if(!n&&!m)break;

        for(int i=0;i<21;i++){

            for(int j=0;j<(1<<20)+5;j++){

                dp[i][j] = -1;
            }
        }

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                scanf("%lf",&ar[i][j]);
            }
        }
        
        long double ans = f(0 , 0);
        ans/=(long double)n;
        
        double a = ans;
        
        printf("%.2f\n",(f(0 , 0)/(double)n)+eps);
    }
    return 0;
}
