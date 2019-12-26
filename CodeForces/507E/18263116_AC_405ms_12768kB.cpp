// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5+9;

vector<pair<int , int> > edges[MAX];
map<pair<int , int> , int >mp;
int n , m , dis1[MAX] , dis2[MAX];
int ar[MAX] , dis3[MAX] , par[MAX];

void bfs()
{
    memset(dis1 , -1 , sizeof(dis1));
    memset(dis2 , -1 , sizeof(dis2));

    queue<int>current;
    current.push(1);
    dis1[1] = 0;
    while(!current.empty()){

        int u = current.front();
        current.pop();
        for(auto v : edges[u]){

            if(dis1[v.first]==-1){

                dis1[v.first] = dis1[u] + 1;
                current.push(v.first);
            }
        }
    }

    current.push(n);
    dis2[n] = 0;
    while(!current.empty()){

        int u = current.front();
        current.pop();
        for(auto v : edges[u]){

            if(dis2[v.first]==-1){

                dis2[v.first] = dis2[u] + 1;
                current.push(v.first);
            }
        }
    }
}

void f(int now)
{
    //cout << now << " ";
    ar[now] = 1;
    if(par[now]==now)return ;
    f(par[now]);
}

void dijkstra()
{
    priority_queue<pair<int , int > > pq;
    memset(dis3 , -1 , sizeof(dis3));
    dis3[1] = 0;
    pq.push({0 , 1});

    for(int i=0;i<=n;i++)par[i] = i;

    while(!pq.empty()){

        int u = pq.top().second;
        pq.pop();
        for(auto it : edges[u]){

            int v = it.first;
            int c = it.second;

            if(dis3[v]<dis3[u]+c&&dis1[v]+dis2[v]==dis1[n]&&dis1[u]<dis1[v]){

                par[v]=u;
                dis3[v] = dis3[u]+c;
                pq.push({dis3[v] , v});
            }
        }
    }
    memset(ar , 0 , sizeof(ar));
    f(n);
}

int main(void)
{
    scanf("%d %d",&n , &m);
    for(int i=0;i<m;i++){

        int in1 , in2 , in3;
        scanf("%d %d %d",&in1 , &in2 , &in3);
        edges[in1].push_back({in2 , in3});
        edges[in2].push_back({in1 , in3});

        if(in1>in2)swap(in1 , in2);
        mp[{in1 , in2}] = in3;
    }

    bfs();
    dijkstra();

    vector<pair<pair<int , int>  ,int> > ans;
    for(auto it : mp){

        int u = it.first.first;
        int v = it.first.second;
        int c = it.second;

        int t1 = u;
        int t2 = v;
        if(t1>t2)swap(t1 , t2);

        if(ar[t1]==1&&ar[t2]==1){

            if(mp[{t1 , t2}]==0)ans.push_back({{u , v} , 1});
        }
        else{

            if(mp[{t1 , t2}]==1)ans.push_back({{u , v} , 0});
        }
    }
    cout << ans.size() << endl;
    for(auto it : ans)cout << it.first.first << " " << it.first.second << " " << it.second << endl;

    return 0;
}
