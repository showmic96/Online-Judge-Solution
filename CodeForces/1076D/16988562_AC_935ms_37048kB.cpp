// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 300005;
const ll INF = 1e18;

struct s{
    ll u , w , idx;

    s(ll _u , ll _w , ll _idx){

        u = _u;
        w = _w;
        idx = _idx;
    }
};

bool operator < (s A , s B)
{
    return A.w<B.w;
}

ll dis[MAX+9] , dis2[MAX+9];
vector<s> edges[MAX+9];
vector<int>ans;
int n , m , k;
bool vis[MAX+9];

void Dijkstra()
{
    priority_queue<pair<ll , ll> >pq;
    dis[1] = 0;
    pq.push(make_pair(0 , 1));
    while(!pq.empty()){

        ll u = pq.top().second;
        ll now = -pq.top().first;
        pq.pop();

        if(now>dis[u])continue;

        for(int i=0;i<edges[u].size();i++){

            ll v = edges[u][i].u;
            ll c = edges[u][i].w;

            if(dis[v]>dis[u]+c){

                dis[v] = dis[u]+c;
                pq.emplace(make_pair(-dis[v] , v));
            }
        }
    }
}

void Dijkstra2()
{
    priority_queue<pair<ll , ll> >pq;
    dis2[1] = 0;
    pq.push(make_pair(0 , 1));
    while(!pq.empty()){

        ll u = pq.top().second;
        ll now = -pq.top().first;
        pq.pop();
        if(k<=0)break;
        if(now>dis2[u])continue;
        for(int i=0;i<edges[u].size();i++){

            ll v = edges[u][i].u;
            ll c = edges[u][i].w;
            ll id = edges[u][i].idx;

            if(dis[v]==dis2[u]+c&&k>0&&vis[v]==false){

                vis[v] = true;
                dis2[v] = dis2[u]+c;
                k--;
                ans.push_back(id);
                if(k<=0)break;
                pq.emplace(make_pair(-dis2[v] , v));
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;

    for(int i=0;i<m;i++){

        ll in1 , in2 , in3;
        cin >> in1 >> in2 >> in3;

        edges[in1].emplace_back(s(in2 , in3 , i+1));
        edges[in2].emplace_back(s(in1 , in3 , i+1));
    }

    for(int i=0;i<=n;i++){

        dis[i] = dis2[i] = INF;
    }

    memset(vis , false , sizeof(vis));
    Dijkstra();
    Dijkstra2();

    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++)cout << ans[i] << " ";

    return 0;
}
