// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 105;
char ar[MAX][MAX];
int n , m , lvl[MAX][MAX];

int dx[] = {1 , -1 , 1 , -1 , 2 , 2 , -2 , -2};
int dy[] = {2 , 2 , -2 , -2 , 1 , -1 , 1 , -1};

int kingx[] = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};
int kingy[] = {1 , -1 , 0 , 0 , 1 , -1 , 1 , -1};

bool possible(int x , int y)
{
    if(x<0||y<0)return false;
    if(x>=n||y>=m)return false;
    if(ar[x][y]=='A')return false;
    if(ar[x][y]=='B')return false;
    return true;
}

bool Check(int x , int y)
{
    if(x<0||y<0)return false;
    if(x>=n||y>=m)return false;
    if(ar[x][y]=='Z')return false;
    if(lvl[x][y]!=0)return false;
    return true;
}

void bfs(int ux , int uy)
{
    queue<int>current;
    current.push(ux);
    current.push(uy);

    while(!current.empty()){

        ux = current.front();current.pop();
        uy = current.front();current.pop();

        for(int i=0;i<8;i++){

            int vx = ux+kingx[i];
            int vy = uy+kingy[i];

            if(Check(vx , vy)==true){

                lvl[vx][vy] = lvl[ux][uy] + 1;
                current.push(vx);
                current.push(vy);
            }
        }
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d",&n , &m);
        for(int i=0;i<n;i++)scanf("%s",&ar[i]);

        memset(lvl , 0 , sizeof(lvl));

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(ar[i][j]=='Z'){

                    for(int k=0;k<8;k++){

                        int tx = i+dx[k];
                        int ty = j+dy[k];

                        if(possible(tx , ty)==true)lvl[tx][ty] = 1e9;
                    }

                    lvl[i][j] = 1e9;
                }
            }
        }

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(ar[i][j]=='A')bfs(i , j);
            }
        }

        int ans = 1e9;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(ar[i][j]=='B'){

                    ans = min(ans , lvl[i][j]);
                }
            }
        }

        if(ans==0)printf("King Peter, you can't go now!\n");
        else printf("Minimal possible length of a trip is %d\n",ans);
    }
    return 0;
}
