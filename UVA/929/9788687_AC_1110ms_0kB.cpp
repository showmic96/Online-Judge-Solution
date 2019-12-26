// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1234567891011121314;

struct node{

    ll x , y , w;

    node(ll xt , ll yt , ll wt){

        x = xt;
        y = yt;
        w = wt;
    }
};

bool operator<(node A , node B)
{
    return A.w > B.w;
}

int n , m;
ll ar[1111][1111];
ll dis[1111][1111];
bool check[1111][1111];

bool valid(int x ,int y)
{
    if(x<0||y<0)return false;
    if(x>=n||y>=m)return false;
    return true;
}

void Dijkstra()
{
    priority_queue<node>pq;

    pq.push(node(0 , 0 , ar[0][0]));
    dis[0][0] = ar[0][0];

    while(!pq.empty()){

        ll x = pq.top().x;
        ll y = pq.top().y;
        ll w = pq.top().w;
        pq.pop();

        if(check[x][y]==true)continue;
        check[x][y] = true;

        if(valid(x+1 , y)==true && dis[x+1][y] > dis[x][y] + ar[x+1][y]){

            dis[x+1][y] = dis[x][y] + ar[x+1][y];

            pq.push(node(x+1 , y , dis[x+1][y]));
        }

        if(valid(x-1 , y)==true && dis[x-1][y] > dis[x][y] + ar[x-1][y]){

            dis[x-1][y] = dis[x][y] + ar[x-1][y];

            pq.push(node(x-1 , y , dis[x-1][y]));
        }

        if(valid(x , y+1)==true && dis[x][y+1] > dis[x][y] + ar[x][y+1]){

            dis[x][y+1] = dis[x][y] + ar[x][y+1];

            pq.push(node(x , y+1 , dis[x][y+1]));
        }

        if(valid(x , y-1)==true && dis[x][y-1] > dis[x][y] + ar[x][y-1]){

            dis[x][y-1] = dis[x][y] + ar[x][y-1];

            pq.push(node(x , y-1 , dis[x][y-1]));
        }
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d",&n , &m);

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                scanf("%lld",&ar[i][j]);
                dis[i][j] = INF;
                check[i][j] = false;
            }
        }

        Dijkstra();

        printf("%lld\n",dis[n-1][m-1]);
    }
    return 0;
}
