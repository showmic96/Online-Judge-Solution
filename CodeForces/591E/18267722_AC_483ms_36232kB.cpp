// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
string ar[1005];
int n , m , dis[4][1005][1005];

int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

int solve()
{
    memset(dis , -1 , sizeof(dis));
    priority_queue<pair< int , pair<int , int> > >current;

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j]=='1'){

                dis[1][i][j]=0;
                current.push({0 , {i , j}});
            }
        }
    }
    while(!current.empty()){

        int x = current.top().second.first;
        int y = current.top().second.second;
        current.pop();

        for(int i=0;i<4;i++){

            int tx = x+dx[i];
            int ty = y+dy[i];

            if(tx>=0&&ty>=0&&tx<n&&ty<m&&ar[tx][ty]!='#'){

                int t = 0;
                if(ar[tx][ty]=='.')t = 1;
                if(dis[1][tx][ty]==-1||dis[1][tx][ty]>dis[1][x][y]+t){

                    dis[1][tx][ty] = dis[1][x][y]+t;
                    current.push({-dis[1][tx][ty] , {tx , ty}});
                }
            }
        }
    }

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j]=='2'){

                dis[2][i][j]=0;
                current.push({0 , {i , j}});
            }
        }
    }
    while(!current.empty()){

        int x = current.top().second.first;
        int y = current.top().second.second;
        current.pop();

        for(int i=0;i<4;i++){

            int tx = x+dx[i];
            int ty = y+dy[i];

            if(tx>=0&&ty>=0&&tx<n&&ty<m&&ar[tx][ty]!='#'){

                int t = 0;
                if(ar[tx][ty]=='.')t = 1;
                if(dis[2][tx][ty]==-1||dis[2][tx][ty]>dis[2][x][y]+t){

                    dis[2][tx][ty] = dis[2][x][y]+t;
                    current.push({-dis[2][tx][ty] , {tx , ty}});
                }
            }
        }
    }

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j]=='3'){

                dis[3][i][j]=0;
                current.push({0 , {i , j}});
            }
        }
    }
    while(!current.empty()){

        int x = current.top().second.first;
        int y = current.top().second.second;
        current.pop();

        for(int i=0;i<4;i++){

            int tx = x+dx[i];
            int ty = y+dy[i];

            if(tx>=0&&ty>=0&&tx<n&&ty<m&&ar[tx][ty]!='#'){

                int t = 0;
                if(ar[tx][ty]=='.')t = 1;
                if(dis[3][tx][ty]==-1||dis[3][tx][ty]>dis[3][x][y]+t){

                    dis[3][tx][ty] = dis[3][x][y]+t;
                    current.push({-dis[3][tx][ty] , {tx , ty}});
                }
            }
        }
    }

    int mi = 1e9;

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j]!='#'&&dis[1][i][j]>=0&&dis[2][i][j]>=0&&dis[3][i][j]>=0){

                mi = min(mi , dis[1][i][j]+dis[2][i][j]+dis[3][i][j]-2*(ar[i][j]=='.'));
            }
        }
    }
    if(mi==1e9)mi = -1;
    return mi;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++)cin >> ar[i];

    cout << max(-1 , solve()) << endl;

    return 0;
}
