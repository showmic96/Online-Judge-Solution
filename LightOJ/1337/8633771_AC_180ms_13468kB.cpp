// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 555;
char ar[MAX][MAX];

int m , n , q , counter;
int dp[MAX][MAX];
bool isVisited[MAX][MAX];

void dfs(int i ,int j)
{
    if(i<0||j<0)return ;
    if(i>=m||j>=n)return ;

    if(ar[i][j]=='#')return ;

    if(isVisited[i][j]==true) return;

    isVisited[i][j] = true;

    if(ar[i][j]=='C')counter++;

    dfs(i , j+1);
    dfs(i , j-1);
    dfs(i+1 , j);
    dfs(i-1 , j);
}

void f(int i , int j , int value)
{
    if(i<0||j<0)return ;
    if(i>=m||j>=n)return ;

    if(ar[i][j]=='#')return ;

    if(dp[i][j]!=-1)return ;

    dp[i][j] = value;

    f(i , j+1 , value);
    f(i , j-1 , value);
    f(i+1 , j , value);
    f(i-1 , j , value);

}

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        memset(dp , -1 , sizeof(dp));
        memset(isVisited , false , sizeof(isVisited));

        scanf("%d %d %d",&m , &n , &q);

        for(int j=0;j<m;j++)scanf("%s",&ar[j]);

        printf("Case %d:\n",i+1);

        while(q--){

            int in1 , in2;

            scanf("%d %d",&in1 , &in2);

            if(dp[in1-1][in2-1]==-1){

                counter = 0;
                dfs(in1-1 , in2-1);

                f(in1-1 , in2-1 , counter);
            }

            printf("%d\n", dp[in1-1][in2-1]);
        }
    }
    return 0;
}
