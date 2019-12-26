// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 9999959999;
double dp[105][305];
bool vis[105][305];
double dp2[105][305];
bool vis2[105][305];

double f(int n , int m)
{
    if(n==0)return (double)m;
    if(vis[n][m]==true)return dp[n][m];
    vis[n][m] = true;
    double value = 0;
    double tot = n+m;
    if(n>0)value+=(double)n/tot*f(n-1 , m+1);
    if(m>0)value+=(double)m/tot*f(n , m-1);

    return dp[n][m] = value;
}

double f2(int n , int m)
{
    if(n==0)return (double)0;
    if(vis2[n][m]==true)return dp2[n][m];
    vis2[n][m] = true;
    double value = 1;
    double tot = n+m;
    if(n>0)value+=(double)n/tot*f2(n-1 , m+1);
    if(m>0)value+=(double)m/tot*f2(n , m-1);

    return dp2[n][m] = value;
}

int main(void)
{
    memset(vis , false , sizeof(vis));
    memset(vis2 , false , sizeof(vis2));

    int n , m;
    while(scanf("%d %d",&n , &m)==2){
        if(n==0&&m==0)break;
        printf("%.14f %.14f\n",f(n , m) , f2(n , m));
    }
    return 0;
}
