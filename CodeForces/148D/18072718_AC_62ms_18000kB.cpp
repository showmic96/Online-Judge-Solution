// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1000+9;

bool vis[MAX][MAX][2];
double dp[MAX][MAX][2];

double f(int n , int m , int state)
{
    if(n<=0)return 0;
    if(vis[n][m][state]==true)return dp[n][m][state];
    vis[n][m][state] = true;
    double value = 0;

    if(state==0){

        value+=(double)n/(m+n);
        value+=f(n , m-1 , state^1)*(double)m/(m+n);
    }
    else{

        double t = (double)m/(n+m);

        if(m-2>=0&&n-1>=0){

            value+=f(n , m-2 , state^1)*t*(double)(m-1)/(m+n-1);
            value+=f(n-1 , m-1 , state^1)*t*(double)(n)/(m+n-1);
        }
        else if(m-1>=0&&n-1>=0){

            value+=f(n-1,m-1 , state^1)*t;
        }
        else if(m-2>=0){

            value+=f(n , m-2 , state^1)*t;
        }
    }

    return dp[n][m][state] = value;
}

int main(void)
{
    int n , m;
    scanf("%d %d",&n , &m);
    memset(vis , false , sizeof(vis));

    double ans = f(n , m , 0);
    printf("%.14f\n",ans);

    return 0;
}
