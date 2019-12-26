// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int r1 , r2 , r3 , c1 , c2 , c3;
int level[9][9];

bool valid(int i , int j)
{
    if(i==r3&&j==c3)return false;

    if(i>8||j>8||i<1||j<1)return false;

    if(level[i][j]!=0)return false;

    return true;
}

void bfs(int u , int v)
{
    queue<int>current;

    current.push(u);
    current.push(v);

    while(!current.empty()){

        u = current.front();current.pop();
        v = current.front();current.pop();

        if(valid(u+1 , v)==true){

            level[u+1][v] = level[u][v] + 1;
            current.push(u+1);
            current.push(v);
        }

        if(valid(u-1 , v)==true){

            level[u-1][v] = level[u][v] + 1;
            current.push(u-1);
            current.push(v);
        }

        if(valid(u , v+1)==true){

            level[u][v+1] = level[u][v] + 1;
            current.push(u);
            current.push(v+1);
        }

        if(valid(u , v-1)==true){

            level[u][v-1] = level[u][v] + 1;
            current.push(u);
            current.push(v-1);
        }

        if(valid(u+1 , v+1)==true){

            level[u+1][v+1] = level[u][v] + 1;
            current.push(u+1);
            current.push(v+1);
        }

        if(valid(u+1 , v-1)==true){

            level[u+1][v-1] = level[u][v] + 1;
            current.push(u+1);
            current.push(v-1);
        }

        if(valid(u-1 , v+1)==true){

            level[u-1][v+1] = level[u][v] + 1;
            current.push(u-1);
            current.push(v+1);
        }

        if(valid(u-1 , v-1)==true){

            level[u-1][v-1] = level[u][v] + 1;
            current.push(u-1);
            current.push(v-1);
        }
    }
}

int main(void)
{
    int c = 0;

    while(scanf("%d %d %d %d %d %d",&r1 , &c1 , &r2 , &c2 , &r3 , &c3)==6){

        for(int i=1;i<=8;i++){

            for(int j=1;j<=8;j++){

                level[i][j] = 0;
            }
        }

        bfs(r1 , c1);

        printf("Case %d: %d\n",++c , level[r2][c2]);
    }
    return 0;
}
