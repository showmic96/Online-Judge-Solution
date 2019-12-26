// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3+9;

string ar[MAX+9];
int dis[MAX+9][MAX+9];
int n , m;

bool possible(int x1 , int y1 , int x2 , int y2)
{
    if(x1<0||y1<0)return false;
    if(x1>=n||y1>=m)return false;

    if(dis[x1][y1]==-1)return true;
    if(dis[x1][y1]<=dis[x2][y2])return false;

    return true;
}

bool psbl(int x1 , int y1 , int x2 , int y2)
{
    if(x1<0||y1<0)return false;
    if(x1>=n||y1>=m)return false;

    if(dis[x1][y1]==-1)return true;
    if(dis[x1][y1]<=dis[x2][y2]+1)return false;

    return true;
}

void bfs(int u , int v)
{
    deque<pair<int , int> > current;
    current.push_back(make_pair(u , v));

    dis[u][v] = 0;

    while(!current.empty()){

        u = current.front().first;
        v = current.front().second;
        current.pop_front();

        if(ar[u][v]=='0'){

            if(possible(u-1 , v , u , v)==true){

                current.push_front(make_pair(u-1 , v));
                dis[u-1][v] = dis[u][v];
            }
        }

        if(ar[u][v]=='1'){

            if(possible(u-1 , v+1 , u , v)==true){

                current.push_front(make_pair(u-1 , v+1));
                dis[u-1][v+1] = dis[u][v];
            }
        }

        if(ar[u][v]=='2'){

            if(possible(u , v+1 , u , v)==true){

                current.push_front(make_pair(u , v+1));
                dis[u][v+1] = dis[u][v];
            }
        }

        if(ar[u][v]=='3'){

            if(possible(u+1 , v+1 , u , v)==true){

                current.push_front(make_pair(u+1 , v+1));
                dis[u+1][v+1] = dis[u][v];
            }
        }

        if(ar[u][v]=='4'){

            if(possible(u+1 , v , u , v)==true){

                current.push_front(make_pair(u+1 , v));
                dis[u+1][v] = dis[u][v];
            }
        }

        if(ar[u][v]=='5'){

            if(possible(u+1 , v-1 , u , v)==true){

                current.push_front(make_pair(u+1 , v-1));
                dis[u+1][v-1] = dis[u][v];
            }
        }

        if(ar[u][v]=='6'){

            if(possible(u , v-1 , u , v)==true){

                current.push_front(make_pair(u , v-1));
                dis[u][v-1] = dis[u][v];
            }
        }

        if(ar[u][v]=='7'){

            if(possible(u-1 , v-1 , u , v)==true){

                current.push_front(make_pair(u-1 , v-1));
                dis[u-1][v-1] = dis[u][v];
            }
        }


        if(psbl(u+1 , v , u , v)==true){

            current.push_back(make_pair(u+1 , v));
            dis[u+1][v] = dis[u][v]+1;
        }
        if(psbl(u-1 , v , u , v)==true){

            current.push_back(make_pair(u-1 , v));
            dis[u-1][v] = dis[u][v]+1;
        }
        if(psbl(u , v+1 , u , v)==true){

            current.push_back(make_pair(u , v+1));
            dis[u][v+1] = dis[u][v]+1;
        }
        if(psbl(u , v-1 , u , v)==true){

            current.push_back(make_pair(u , v-1));
            dis[u][v-1] = dis[u][v]+1;
        }
        if(psbl(u+1 , v+1 , u , v)==true){

            current.push_back(make_pair(u+1 , v+1));
            dis[u+1][v+1] = dis[u][v]+1;
        }
        if(psbl(u+1 , v-1 , u , v)==true){

            current.push_back(make_pair(u+1 , v-1));
            dis[u+1][v-1] = dis[u][v]+1;
        }
        if(psbl(u-1 , v+1 , u , v)==true){

            current.push_back(make_pair(u-1 , v+1));
            dis[u-1][v+1] = dis[u][v]+1;
        }
        if(psbl(u-1 , v-1 , u , v)==true){

            current.push_back(make_pair(u-1 , v-1));
            dis[u-1][v-1] = dis[u][v]+1;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;i++)cin >> ar[i];

    int q;
    cin >> q;

    while(q--){

        for(int i=0;i<=n;i++){

            for(int j=0;j<=m;j++)dis[i][j] = -1;
        }

        int st1 , st2 , en1 , en2;
        cin >> st1 >> st2 >> en1 >> en2;

        st1--;st2--;en1--;en2--;

        bfs(st1 , st2);
        cout << dis[en1][en2] << endl;
    }

    return 0;
}
