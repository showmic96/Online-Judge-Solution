#include<bits/stdc++.h>
using namespace std;

char ar[100][100];
int a , b;
int level[21][21];//map<pair<int,int>,int>level;
bool is_visited[21][21];//map<pair<int,int>,int>is_visited;
queue<int>current;

void set_up()
{
    for(int i=0;i<21;i++){

        for(int j=0;j<21;j++){
            level[i][j]=0;
            is_visited[i][j]=false;
        }
    }
}

void bfs(int x , int y)
{
    set_up();

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

        if((ar[temp_x+1][temp_y]=='.'||ar[temp_x+1][temp_y]=='a'||ar[temp_x+1][temp_y]=='b'||ar[temp_x+1][temp_y]=='c')&&is_visited[temp_x+1][temp_y]==false){

            is_visited[temp_x+1][temp_y]=true;
            level[temp_x+1][temp_y] = level[temp_x][temp_y]+1;

            current.push(temp_x+1);
            current.push(temp_y);
        }

        if((ar[temp_x-1][temp_y]=='.'||ar[temp_x-1][temp_y]=='a'||ar[temp_x-1][temp_y]=='b'||ar[temp_x-1][temp_y]=='c')&&is_visited[temp_x-1][temp_y]==false){

            is_visited[temp_x-1][temp_y]=true;
            level[temp_x-1][temp_y] = level[temp_x][temp_y]+1;

            current.push(temp_x-1);
            current.push(temp_y);
        }


        if((ar[temp_x][temp_y+1]=='.'||ar[temp_x][temp_y+1]=='a'||ar[temp_x][temp_y+1]=='b'||ar[temp_x][temp_y+1]=='c')&&is_visited[temp_x][temp_y+1]==false){

            is_visited[temp_x][temp_y+1]=true;
            level[temp_x][temp_y+1] = level[temp_x][temp_y]+1;

            current.push(temp_x);
            current.push(temp_y+1);
        }


        if((ar[temp_x][temp_y-1]=='.'||ar[temp_x][temp_y-1]=='a' ||ar[temp_x][temp_y-1]=='b'||ar[temp_x][temp_y-1]=='c')&&is_visited[temp_x][temp_y-1]==false){

            is_visited[temp_x][temp_y-1]=true;
            level[temp_x][temp_y-1] = level[temp_x][temp_y]+1;
            current.push(temp_x);
            current.push(temp_y-1);
        }

    }


}

int main(void)
{
    int t;
    cin >> t;
    int bollosom_x , bollosom_y ,bubbles_x ,bubbles_y , buttercup_x , buttercup_y;

    for(int i=0;i<t;i++){

        cin >> a >> b;

        for(int j=0;j<a;j++)cin >> ar[j];

        for(int j=0;j<a;j++){

            for(int k=0;k<b;k++){
                if(ar[j][k]=='h'){bfs(j,k);}
                if(ar[j][k]=='a'){bollosom_x = j;bollosom_y=k;}
                if(ar[j][k]=='b'){bubbles_x = j; bubbles_y = k;}
                if(ar[j][k]=='c'){buttercup_x = j; buttercup_y = k;}
            }
        }

        int dis[3];

        dis[0]=level[bollosom_x][bollosom_y];

        dis[1]=level[buttercup_x][buttercup_y];

        dis[2]=level[bubbles_x][bubbles_y];


        sort(dis,dis+3);
        printf("Case %d: ",i+1);
        cout << dis[2]-1 << endl;


    }

    return 0;
}
