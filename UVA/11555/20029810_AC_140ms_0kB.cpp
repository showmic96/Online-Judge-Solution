// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2005;
double dp[MAX][MAX] , l , w , dis;
vector<double>v;
bool vis[MAX][MAX];
int n;

double f(int i , int j)
{
    if(i+j==n)return 0;
    if(vis[i][j]==true)return dp[i][j];
    vis[i][j] = true;
    double value = 1e38;
    if(i<n/2){
        value = min(value , f(i+1, j)+abs(v[i+j]-dis*i));
    }
    if(j<n/2){
        value = min(value , f(i , j+1)+sqrt((v[i+j]-dis*j)*(v[i+j]-dis*j)+w*w));
    }
    return dp[i][j] = value;
}

int main(void)
{
    while(scanf("%d %lf %lf",&n , &l , &w)==3){
        v.clear();
        for(int i=0;i<n;i++){
            double in;
            scanf("%lf",&in);
            v.push_back(in);
        }
        dis = l/(n/2 - 1);
        sort(v.begin() , v.end());
        memset(vis , false , sizeof(vis));
        printf("%.14f\n",f(0 , 0));
    }
    return 0;
}
