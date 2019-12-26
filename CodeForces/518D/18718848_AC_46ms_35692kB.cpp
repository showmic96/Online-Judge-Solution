// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 2005;
bool vis[MAX][MAX];
double dp[MAX][MAX] , p;
int n , t;

double f(int tot , int t)
{
    if(t==0)return min(tot , n);
    if(vis[tot][t]==true)return dp[tot][t];
    vis[tot][t] = true;
    double value = f(tot+1 , t-1)*p;
    value+=f(tot , t-1)*(1-p);
    return dp[tot][t] = value;
}

int main(void)
{
    scanf("%d %lf %d",&n , &p , &t);
    memset(vis , false , sizeof(vis));
    printf("%.14f\n",f(0 , t));
    return 0;
}
