// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 105;
string ar[MAX];
int lvl[MAX][MAX][4];

struct s{

    int u , v , cost , dir;
    s(int _u , int _v , int _cost , int _dir){

        u = _u;
        v = _v;
        cost = _cost;
        dir = _dir;
    }
};

bool operator <(s A , s B)
{
    return A.cost > B.cost;
}

int n , m;

bool possible(int x , int y)
{
    if(x<0||y<0)return false;
    if(x>=n||y>=m)return false;
    if(ar[x][y]=='*')return false;
    return true;
}

void Dijkstra(int ux , int uy)
{
    priority_queue<s> pq;
    lvl[ux][uy][0] = 0;
    lvl[ux][uy][1] = 0;
    lvl[ux][uy][2] = 0;
    lvl[ux][uy][3] = 0;

    pq.push(s(ux , uy , 0 , 0));
    pq.push(s(ux , uy , 0 , 1));
    pq.push(s(ux , uy , 0 , 2));
    pq.push(s(ux , uy , 0 , 3));

    while(!pq.empty()){

        ux = pq.top().u;
        uy = pq.top().v;
        int cost = pq.top().cost;
        int dir = pq.top().dir;

        pq.pop();

        int vx = ux + 1;
        int vy = uy;

        if(possible(vx , vy)==true){

            if(dir==0){

                if(lvl[vx][vy][0]>cost){

                    lvl[vx][vy][0] = cost;
                    pq.push(s(vx , vy , lvl[vx][vy][0] , 0));
                }
            }
            else{

                if(lvl[vx][vy][0]>cost+1){

                    lvl[vx][vy][0] = cost+1;
                    pq.push(s(vx , vy , lvl[vx][vy][0] , 0));
                }
            }
        }

        vx = ux - 1;
        vy = uy;

        if(possible(vx , vy)==true){

            if(dir==1){

                if(lvl[vx][vy][1]>cost){

                    lvl[vx][vy][1] = cost;
                    pq.push(s(vx , vy , lvl[vx][vy][1] , 1));
                }
            }
            else{

                if(lvl[vx][vy][1]>cost+1){

                    lvl[vx][vy][1] = cost+1;
                    pq.push(s(vx , vy , lvl[vx][vy][1] , 1));
                }
            }
        }

        vx = ux;
        vy = uy + 1;

        if(possible(vx , vy)==true){

            if(dir==2){

                if(lvl[vx][vy][2]>cost){

                    lvl[vx][vy][2] = cost;
                    pq.push(s(vx , vy , lvl[vx][vy][2] , 2));
                }
            }
            else{

                if(lvl[vx][vy][2]>cost+1){

                    lvl[vx][vy][2] = cost+1;
                    pq.push(s(vx , vy , lvl[vx][vy][2] , 2));
                }
            }
        }

        vx = ux;
        vy = uy - 1;

        if(possible(vx , vy)==true){

            if(dir==3){

                if(lvl[vx][vy][3]>cost){

                    lvl[vx][vy][3] = cost;
                    pq.push(s(vx , vy , lvl[vx][vy][3] , 3));
                }
            }
            else{

                if(lvl[vx][vy][3]>cost+1){

                    lvl[vx][vy][3] = cost+1;
                    pq.push(s(vx , vy , lvl[vx][vy][3] , 3));
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> n;

    for(int i=0;i<n;i++)cin >> ar[i];
    for(int i=0;i<=n;i++){

        for(int j=0;j<=m;j++){

            lvl[i][j][0] = 1e9;
            lvl[i][j][1] = 1e9;
            lvl[i][j][2] = 1e9;
            lvl[i][j][3] = 1e9;
        }
    }

    int ans = 1e9;
    bool check = false;

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j]=='C'&&check==false){

                Dijkstra(i , j);
                check = true;
            }
            else if(ar[i][j]=='C'){

                ans = min(ans , lvl[i][j][0]);
                ans = min(ans , lvl[i][j][1]);
                ans = min(ans , lvl[i][j][2]);
                ans = min(ans , lvl[i][j][3]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
