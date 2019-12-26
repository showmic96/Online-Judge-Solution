// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int n , m , k , counter, loop;

string ar[11];

int grid[11][11];

void dfs(int i , int j , int c)
{
    if(i<0||j<0){

        counter = c;
        return ;
    }

    if(i>=n||j>=m){

        counter = c;
        return ;
    }

    if(grid[i][j]!=-1){

        counter = grid[i][j];
        loop = c - grid[i][j];
        return ;
    }

    grid[i][j] = c;

    if(ar[i][j]=='N'){

        dfs(i-1 , j , c+1);
    }

    else if(ar[i][j]=='S'){

        dfs(i+1 , j , c+1);
    }

    else if(ar[i][j]=='E'){

        dfs(i , j+1, c+1);
    }

    else dfs(i ,j-1 , c+1);

    return ;
}

int main(void)
{
    while(scanf("%d %d %d", &n , &m , &k)==3){

        if(n==0)break;

        for(int i=0;i<n;i++)cin >> ar[i];

        loop = -1 , counter = 0;

        memset(grid , -1 , sizeof(grid));

        dfs(0 , k-1 , 0);

        if(loop==-1)printf("%d step(s) to exit\n",counter);
        else printf("%d step(s) before a loop of %d step(s)\n",counter , loop);
    }

    return 0;
}
