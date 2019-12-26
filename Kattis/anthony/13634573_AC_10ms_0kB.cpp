// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double dp[1005][1005];
vector<double>v;
int n , m;

double f(int i , int j)
{
    if(i==0)return 0;
    if(j==0)return 1;

    if(dp[i][j]!=-1)return dp[i][j];

    double value = 0;

    value+=v[i+j-2]*(f(i , j-1));
    value+=(1-v[i+j-2])*(f(i-1 ,j));

    return dp[i][j] = value;
}

int main(void)
{

    for(int i=0;i<1005;i++){

        for(int j=0;j<1005;j++)dp[i][j] = -1;
    }

    v.clear();
    int n , m;

    scanf("%d %d",&n , &m);

    for(int i=0;i<n+m-1;i++){

        double in;
        scanf("%lf",&in);
        v.push_back(in);
    }

    printf("%.6f\n",f(n , m));

    return 0;
}
