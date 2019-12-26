#include<bits/stdc++.h>
using namespace std;
#define si 10100

char ar[si][si];
int a , b;
int level[si][si];//map<pair<int,int>,int>level;
bool is_visited[si][si];//map<pair<int,int>,int>is_visited;
queue<int>current;

void set_up(int x , int y)
{
    for(int i=0;i<=x;i++){

        for(int j=0;j<=y;j++){
            level[i][j]=0;
            is_visited[i][j]=false;
            ar[i][j]='A';
        }
    }
}

void bfs(int x , int y)
{
//    set_up();

    is_visited[x][y]=true;
    level[x][y]=1;
    current.push(x);
    current.push(y);

    int temp_x , temp_y;

    while(!current.empty()){

        temp_x = current.front();
        current.pop();
        temp_y = current.front();
        current.pop();

        if(temp_x<0||temp_y<0)continue;
        if(temp_x>a||temp_y>b)continue;

        if(ar[temp_x+1][temp_y]=='A'&&is_visited[temp_x+1][temp_y]==false){

            is_visited[temp_x+1][temp_y]=true;
            level[temp_x+1][temp_y] = level[temp_x][temp_y]+1;

            current.push(temp_x+1);
            current.push(temp_y);
        }

        if(ar[temp_x-1][temp_y]=='A'&&is_visited[temp_x-1][temp_y]==false){

            is_visited[temp_x-1][temp_y]=true;
            level[temp_x-1][temp_y] = level[temp_x][temp_y]+1;

            current.push(temp_x-1);
            current.push(temp_y);
        }


        if(ar[temp_x][temp_y+1]=='A'&&is_visited[temp_x][temp_y+1]==false){

            is_visited[temp_x][temp_y+1]=true;
            level[temp_x][temp_y+1] = level[temp_x][temp_y]+1;

            current.push(temp_x);
            current.push(temp_y+1);
        }


        if(ar[temp_x][temp_y-1]=='A'&&is_visited[temp_x][temp_y-1]==false){

            is_visited[temp_x][temp_y-1]=true;
            level[temp_x][temp_y-1] = level[temp_x][temp_y]+1;
            current.push(temp_x);
            current.push(temp_y-1);
        }

    }


}

int main(void)
{
    int  c , d , e , f;
    int from1 ,from2 , to1 , to2;
    while(cin >> a >> b){

        if(!a&&!b)break;
        set_up(a,b);

        cin >> c;

        while(c--){

            cin >> d;
            cin >> f;
            for(int i=0;i<f;i++){

                cin >> e;
                ar[d][e]='B';
            }

        }

        cin >> from1 >> from2 >> to1 >> to2;

        bfs(from1,from2);

        cout << level[to1][to2]-1 << endl;
    }


    return 0;
}
