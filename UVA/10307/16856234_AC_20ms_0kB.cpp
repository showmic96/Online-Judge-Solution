// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , m , par[55*55] , lvl[55][55];
string ar[55];

struct edges{

    int u , v , w;
    edges(int _u , int _v , int _w){

        u = _u;
        v = _v;
        w = _w;
    }
};

vector<edges>v;

bool cmp(edges A , edges B)
{
    return A.w<B.w;
}

int Find(int x)
{
    if(x==par[x])return x;
    return par[x] = Find(par[x]);
}

void Union(int x ,int y)
{
    int px = Find(x);
    int py = Find(y);

    par[py] = px;
}

bool possible(int x,  int y)
{
    if(x<0||y<0||x>=n||y>=m)return false;
    if(ar[x][y]=='#')return false;
    if(lvl[x][y]!=-1)return false;
    return true;
}

void bfs(int u , int v)
{
    queue<int>current;
    current.push(u);
    current.push(v);

    memset(lvl , -1 , sizeof(lvl));

    lvl[u][v] = 0;

    while(!current.empty()){

        u = current.front();current.pop();
        v = current.front();current.pop();

        if(possible(u+1 , v)==true){

            lvl[u+1][v] = lvl[u][v]+1;
            current.push(u+1);
            current.push(v);
        }

        if(possible(u-1 , v)==true){

            lvl[u-1][v] = lvl[u][v]+1;
            current.push(u-1);
            current.push(v);
        }

        if(possible(u , v+1)==true){

            lvl[u][v+1] = lvl[u][v]+1;
            current.push(u);
            current.push(v+1);
        }

        if(possible(u , v-1)==true){

            lvl[u][v-1] = lvl[u][v]+1;
            current.push(u);
            current.push(v-1);
        }
    }
}

void Kruskal()
{
    int ans = 0;

    for(int i=0;i<v.size();i++){

        if(Find(v[i].u)==Find(v[i].v))continue;

        ans+=v[i].w;
        Union(v[i].u , v[i].v);
    }

    cout << ans << endl;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){

        v.clear();
        cin >> m >> n;
        cin.ignore();

        for(int i=0;i<n;i++)getline(cin , ar[i]);
        for(int i=0;i<55*55;i++)par[i] = i;

        int counter = 1;
        map<pair<int , int> , int > mp;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(ar[i][j]=='A'||ar[i][j]=='S'){

                    mp[make_pair(i , j)] = counter;
                    counter++;
                }
            }
        }

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(ar[i][j]=='A'||ar[i][j]=='S'){

                    bfs(i , j);
                    for(auto it=mp.begin();it!=mp.end();it++){

                        int t1 = it->first.first;
                        int t2 = it->first.second;

                        if(lvl[t1][t2]>0)v.push_back(edges(mp[make_pair(i , j)] , mp[make_pair(t1 , t2)] , lvl[t1][t2]));
                    }
                }
            }
        }

        sort(v.begin() , v.end() , cmp);
        Kruskal();
    }

    return 0;
}
