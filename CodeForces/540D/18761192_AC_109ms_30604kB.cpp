// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 105;
double dp[MAX][MAX][MAX][3];
bool vis[MAX][MAX][MAX][3];

double f(int r , int s , int p , int now)
{
    if(r==0&&s==0){
        if(now==2)return 1;
        return 0;
    }
    if(r==0&&p==0){
        if(now==1)return 1;
        return 0;
    }
    if(s==0&&p==0){
        if(now==0)return 1;
        return 0;
    }
    if(vis[r][s][p][now]==true)return dp[r][s][p][now];
    vis[r][s][p][now] = true;
    double value = 0;
    double tot = r*s+r*p+p*s;
    if(r>0&&s>0){
        value+=f(r , s-1 , p , now)*(double)r*s/tot;
    }
    if(r>0&&p>0){
        value+=f(r-1 , s , p , now)*(double)r*p/tot;
    }
    if(s>0&&p>0){
        value+=f(r , s , p-1 , now)*(double)s*p/tot;
    }
    return dp[r][s][p][now] = value;
}

int main(void)
{
    int r , s , p;
    scanf("%d %d %d",&r , &s , &p);
    memset(vis , false , sizeof(vis));
    printf("%.14f %.14f %.14f\n",f(r , s , p , 0) , f(r , s , p , 1) , f(r , s , p , 2));
    return 0;
}
