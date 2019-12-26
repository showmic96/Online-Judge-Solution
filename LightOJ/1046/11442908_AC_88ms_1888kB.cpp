// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int INF = 1e7;

int level[110][11][11];
bool visited[110][11][11][11];

string ar[11];
int n , m;
queue<int>current;

void pre()
{
    memset(visited , false , sizeof(visited));

    for(int i=0;i<110;i++){

        for(int j=0;j<11;j++){

            for(int k=0;k<11;k++){

                level[i][j][k] = INF;
            }
        }
    }
}

void dfs(int i , int j , int k , int c , int l)
{
    if(i<0||j<0)return;
    if(i>=n||j>=m)return;

    if(visited[c][i][j][k]==true)return ;
    visited[c][i][j][k] = true;

    if(level[c][i][j]==INF){

        level[c][i][j] = l;
        current.push(i);
        current.push(j);
    }

    if(k==0)return ;

    dfs(i+1 , j+2 , k-1 , c , l);
    dfs(i+1 , j-2 , k-1 , c , l);
    dfs(i-1 , j+2 , k-1 , c , l);
    dfs(i-1 , j-2 , k-1 , c , l);
    dfs(i+2 , j+1 , k-1 , c , l);
    dfs(i+2 , j-1 , k-1 , c , l);
    dfs(i-2 , j+1 , k-1 , c , l);
    dfs(i-2 , j-1 , k-1 , c , l);

    return ;

}

void bfs(int i , int j , int k , int c)
{

    while(!current.empty())current.pop();

    level[c][i][j] = 0;

    current.push(i);
    current.push(j);

    while(!current.empty()){

        i = current.front();
        current.pop();
        j = current.front();
        current.pop();

        dfs(i+1 , j+2 , k-1 , c , level[c][i][j]+1);
        dfs(i+1 , j-2 , k-1 , c , level[c][i][j]+1);
        dfs(i-1 , j+2 , k-1 , c , level[c][i][j]+1);
        dfs(i-1 , j-2 , k-1 , c , level[c][i][j]+1);
        dfs(i+2 , j+1 , k-1 , c , level[c][i][j]+1);
        dfs(i+2 , j-1 , k-1 , c , level[c][i][j]+1);
        dfs(i-2 , j+1 , k-1 , c , level[c][i][j]+1);
        dfs(i-2 , j-1 , k-1 , c , level[c][i][j]+1);
    }
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        pre();
        scanf("%d %d",&n, &m);

        for(int i=0;i<n;i++)cin >> ar[i];//scanf("%s",&ar[i]);

        int counter = 0;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(ar[i][j]>='0'&&ar[i][j]<='9'){

                    bfs(i , j , ar[i][j]-'0' , counter);
                    counter++;
                }
            }
        }

        int ans = 1e9;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                int temp = 0;

                for(int k=0;k<counter;k++){

                    temp += level[k][i][j];
                }

                ans = min(temp , ans);
            }
        }

        if(ans>1e6)ans = -1;

        printf("Case %d: %d\n",++c , ans);
    }

    return 0;
}
