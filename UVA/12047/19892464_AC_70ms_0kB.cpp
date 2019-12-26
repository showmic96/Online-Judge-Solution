// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 10000+5;
const ll INF = 1e17;
vector<pair<ll , ll > > edges[MAX+9] , re[MAX+9];
ll dis1[MAX] ,dis2[MAX];

void Dijkstra1(int st)
{
    dis1[st] = 0;
    priority_queue<pair<ll , ll > > pq;
    pq.push({0 , st});
    while(!pq.empty()){
        ll c = -pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        for(auto it:edges[u]){
            c = it.second;
            ll v = it.first;
            if(dis1[v]>dis1[u]+c){
                dis1[v] = dis1[u]+c;
                pq.push({-dis1[v] , v});
            }
        }
    }
}
void Dijkstra2(int st)
{
    dis2[st] = 0;
    priority_queue<pair<ll , ll > > pq;
    pq.push({0 , st});
    while(!pq.empty()){
        ll c = -pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        for(auto it:re[u]){
            c = it.second;
            ll v = it.first;
            if(dis2[v]>dis2[u]+c){
                dis2[v] = dis2[u]+c;
                pq.push({-dis2[v] , v});
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n , m , s , t , p;
        cin >> n >> m >> s >> t >> p;
        for(int i=0;i<=n;i++){
            edges[i].clear();re[i].clear();
            dis1[i] = dis2[i] = INF;
        }
        for(int i=0;i<m;i++){
            ll in1 , in2 , in3;
            cin >> in1 >> in2 >> in3;
            edges[in1].push_back({in2 , in3});
            re[in2].push_back({in1 , in3});
        }
        Dijkstra1(s);
        Dijkstra2(t);
        if(dis1[t]>p)cout << -1 << endl;
        else{
            ll ans = 0;
            for(int i=0;i<=n;i++){
                for(int j=0;j<edges[i].size();j++){
                    if(dis1[i]+dis2[edges[i][j].first]+edges[i][j].second<=p){
                        ans = max(ans , edges[i][j].second);
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}