// In the name of Allah the Most Merciful.
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int MAX = 1e4+9;
ll INF = 1e18;
 
vector<pair<int , int> > edges[MAX+9] , rEdges[MAX+9];
ll dis1[MAX+9] , dis2[MAX+9] , n;
 
void init()
{
    for(int i=0;i<=MAX;i++){
 
        edges[i].clear();
        rEdges[i].clear();
 
        dis1[i] = INF;
        dis2[i] = INF;
    }
}
 
ll Dijkstra(ll s , ll t , ll p)
{
    priority_queue<pair<ll , ll> > pq;
 
    dis1[s] = 0;
 
    pq.push(make_pair(0 , s));
 
    while(!pq.empty()){
 
        ll c1 = -pq.top().first;
        ll u = pq.top().second;
 
        pq.pop();
 
        int si = edges[u].size();
 
        for(int i=0;i<si;i++){
 
            ll v = edges[u][i].first;
            ll c = edges[u][i].second;
 
            if(dis1[v]>dis1[u]+c){
 
                dis1[v] = dis1[u]+c;
                pq.push(make_pair(-dis1[v] , v));
            }
        }
    }
 
    dis2[t] = 0;
    pq.push(make_pair(0 , t));
 
    while(!pq.empty()){
 
        ll c1 = -pq.top().first;
        ll u = pq.top().second;
 
        pq.pop();
 
        int si = rEdges[u].size();
 
        for(int i=0;i<si;i++){
 
            ll v = rEdges[u][i].first;
            ll c = rEdges[u][i].second;
 
            if(dis2[v]>dis2[u]+c){
 
                dis2[v] = dis2[u]+c;
                pq.push(make_pair(-dis2[v] , v));
            }
        }
    }
 
    ll ans = 0;
 
    for(int i=1;i<=n;i++){
 
        int si = edges[i].size();
 
        for(int j=0;j<si;j++){
 
            if(dis1[i]+dis2[edges[i][j].first]+edges[i][j].second<=p){
 
                ans = max(ans , (ll)edges[i][j].second);
            }
        }
    }
 
    if(ans==0) ans = -1;
 
    return ans;
}
 
int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
 
    while(t--){
 
        init();
 
        ll m , s , t , p;
        scanf("%lld %lld %lld %lld %lld",&n, &m, &s , &t , &p);
 
 
        while(m--){
 
            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);
 
            edges[in1].push_back(make_pair(in2 , in3));
            rEdges[in2].push_back(make_pair(in1 , in3));
        }
 
        ll ans = Dijkstra(s , t , p);
 
        printf("%lld\n", ans);
    }
 
    return 0;
}