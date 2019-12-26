#include<bits/stdc++.h>
using namespace std;

bool isVisited[8][8];
int level[8][8];
char ch1 , ch2;
int in1_x , in2_x , in1_y , in2_y;
bool check = false;

void ini()
{
    check = false;
    for(int i=0;i<8;i++){

        for(int j=0;j<8;j++){

            isVisited[i][j]=false;
            level[i][j]=0;
        }
    }
}

void dfs(int i , int j)
{
    if(i==in2_x&&j==in2_y)check=true;

    if(check==true)return;

    if(isVisited[i][j]==true)return;

    isVisited[i][j]=true;

    if(i+2<8&&j+1<8){

        if(isVisited[i+2][j+1]==false)level[i+2][j+1]=level[i][j]+1;
        dfs(i+2,j+1);
    }

    if(i+2<8&&j-1>-1){

        if(isVisited[i+2][j-1]==false)level[i+2][j-1]=level[i][j]+1;
        dfs(i+2,j-1);
    }

    if(i-2>-1&&j+1<8){

        if(isVisited[i-2][j+1]==false)level[i-2][j+1]=level[i][j]+1;
        dfs(i-2,j+1);
    }

    if(i-2>-1&&j-1>-1){

        if(isVisited[i-2][j-1]==false)level[i-2][j-1]=level[i][j]+1;
        dfs(i-2,j-1);
    }

    if(i+1<8&&j+2<8){

        if(isVisited[i+1][j+2]==false)level[i+1][j+2]=level[i][j]+1;
        dfs(i+1,j+2);
    }

    if(i+1<8&&j-2>-1){

        if(isVisited[i+1][j-2]==false)level[i+1][j-2]=level[i][j]+1;
        dfs(i+1,j-2);
    }

    if(i-1>-1&&j+2<8){

        if(isVisited[i-1][j+2]==false)level[i-1][j+2]=level[i][j]+1;
        dfs(i-1,j+2);
    }

    if(i-1>-1&&j-2>-1){

        if(isVisited[i-1][j-2]==false)level[i-1][j-2]=level[i][j]+1;
        dfs(i-1,j-2);
    }

}

void bfs(int a , int b)
{
    queue<int>current;

    current.push(a);
    current.push(b);

    level[a][b]=1;

    while(!current.empty()){

        int i = current.front();
        current.pop();
        int j = current.front();
        current.pop();

        if(level[i+2][j+1]==0)if(i+2<8&&j+1<8){

        level[i+2][j+1]=level[i][j]+1;
        current.push(i+2);
        current.push(j+1);
        }

        if(level[i+2][j-1]==0)if(i+2<8&&j-1>-1){

            level[i+2][j-1]=level[i][j]+1;
            current.push(i+2);
            current.push(j-1);
        }

        if(level[i-2][j+1]==0)if(i-2>-1&&j+1<8){

            level[i-2][j+1]=level[i][j]+1;
            current.push(i-2);
            current.push(j+1);
        }

        if(level[i-2][j-1]==0)if(i-2>-1&&j-1>-1){

            level[i-2][j-1]=level[i][j]+1;
            current.push(i-2);
            current.push(j-1);
        }

        if(level[i+1][j+2]==0)if(i+1<8&&j+2<8){

            level[i+1][j+2]=level[i][j]+1;
            current.push(i+1);
            current.push(j+2);
        }

        if(level[i+1][j-2]==0)if(i+1<8&&j-2>-1){

            level[i+1][j-2]=level[i][j]+1;
            current.push(i+1);
            current.push(j-2);
        }

        if(level[i-1][j+2]==0)if(i-1>-1&&j+2<8){

            level[i-1][j+2]=level[i][j]+1;
            current.push(i-1);
            current.push(j+2);
        }

        if(level[i-1][j-2]==0)if(i-1>-1&&j-2>-1){

            level[i-1][j-2]=level[i][j]+1;
            current.push(i-1);
            current.push(j-2);
        }


    }
}

int main(void)
{

    while(cin >> ch1 >> in1_y >> ch2 >> in2_y){

        in1_y--;
        in2_y--;

        ini();

        in1_x = ch1 - 'a';
        in2_x = ch2 - 'a';

        bfs(in1_x,in1_y);

        printf("To get from %c%d to %c%d takes %d knight moves.\n",(ch1),(in1_y+1),(ch2),(in2_y+1),level[in2_x][in2_y]-1);


    }

    return 0;
}
