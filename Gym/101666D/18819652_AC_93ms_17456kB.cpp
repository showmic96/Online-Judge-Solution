#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5+9;
vector<pair<ll , ll> > edges[MAX+9];
ll dis1[MAX] , dis[MAX] , par[MAX] , ar[MAX] , dis2[MAX];

void Dijkstra()
{
    for(int i=0;i<=MAX;i++)dis[i] = -1;
    queue<int>pq;
    pq.push(0);
    dis[0] = 0;
    while(!pq.empty()){
        ll u = pq.front();
        pq.pop();
        for(auto it: edges[u]){
            ll v = it.first;
            if(it.second>1e16)continue;
            if(dis[v]==-1){
                dis[v] = dis[u]+1;
                pq.push(v);
                par[v] = u;
            }
        }
    }
}
void Dijkstra2()
{
    for(int i=0;i<=MAX;i++)dis2[i] = 1e18;
    priority_queue<pair<ll , ll > >pq;
    pq.push({0 , 1});
    dis2[1] = 0;
    while(!pq.empty()){
        ll u = pq.top().second;
        ll c = -pq.top().first;
        pq.pop();
        //if(dis2[u]>c)continue;
        for(auto it: edges[u]){
            ll v = it.first;
            ll c = it.second;
            if(dis2[v]>dis2[u]+c){
                dis2[v] = dis2[u]+c;
                pq.push({-dis2[v] , v});
            }
        }
    }
}

int aaa[1000006] , cc = 0;
void f(int x)
{
    int now = x;
    cc = 0;
    while(true){
        if(x==0){break;}
        aaa[cc] = x;
        cc++;
        now = par[x];
        x = now;
    }
}

int main(void)
{
    int n , m;
    scanf("%d %d",&n , &m);
    for(int i=0;i<m;i++){
        ll in1 , in2 , in3;
        scanf("%lld %lld %lld",&in1 , &in2 , &in3);
        edges[in1].push_back({in2 , in3});
        edges[in2].push_back({in1 , in3});
    }
    Dijkstra2();
    for(int i=0;i<n;i++){
        for(int j=0;j<edges[i].size();j++){
            int temp = edges[i][j].first;
            if(dis2[i]==edges[i][j].second+dis2[temp]){
                edges[i][j].second = 1e18;
                //cout << i << " " << edges[i][j].first << " debug" << endl;
            }
        }
    }
    Dijkstra();
    if(dis[1]==-1)printf("impossible\n");
    else{
        f(1);
        printf("%d 0",cc+1);
        for(int i=cc-1;i>=0;i--){
            printf(" %d",aaa[i]);
        }
        printf("\n");
    }
    return 0;
}
