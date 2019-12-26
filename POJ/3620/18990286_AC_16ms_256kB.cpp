// In the name of Allah the Lord of the Worlds.

#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long ll;
int ar[105][105];
bool vis[105][105];
int n , m , k , counter;
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

void dfs(int i , int j)
{
    if(vis[i][j]==true)return ;
    if(ar[i][j]==0)return ;
    vis[i][j] = true;
    counter++;
    for(int i1=0;i1<4;i1++){
        int tx = i+dx[i1];
        int ty = j+dy[i1];
        if(tx>=0&&tx<n&&ty>=0&&ty<m){
            dfs(tx , ty);
        }
    }
}

int main(void)
{
    scanf("%d %d %d",&n , &m , &k);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            vis[i][j] = false;
            ar[i][j] = 0;
        }
    }
    for(int i=0;i<k;i++){
        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        ar[in1-1][in2-1] = 1;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==false&&ar[i][j]==1){
                counter = 0;
                dfs(i , j);
                ans = max(ans , counter);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
