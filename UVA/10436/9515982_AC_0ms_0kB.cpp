// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e19;

map<string , int>mp;
map<int , string>mpd;
double cost[22];
vector<pair<int , double> > edges[22];
int parent[22];
double dis[22];
vector<int>ans;

void Find(int x)
{
    ans.push_back(x);
    if(x==parent[x])return;

    return Find(parent[x]);
}

void Init(int n)
{
    mp.clear();
    mpd.clear();

    for(int i=0;i<22;i++){

        edges[i].clear();
    }
}

void Dijkstra(int u)
{
    priority_queue<pair < double , int> > pq;

    dis[u] = cost[u];

    pq.push(make_pair(0 , u));

    while(!pq.empty()){

        double c1 = -pq.top().first;
        u = pq.top().second;

        pq.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            int v = edges[u][i].first;
            double c = edges[u][i].second;

            if(dis[v]>dis[u]+c+cost[v]){

                dis[v] = dis[u] + c;
                dis[v]+=cost[v];

                parent[v] = u;

                pq.push(make_pair(-dis[v] , v));
            }
        }
    }
}

int main(void)
{
    int t , m = 0;
    scanf("%d",&t);
    while(t--){

        if(m!=0)printf("\n");

        int n;
        scanf("%d",&n);

        Init(n);

        for(int i=1;i<=n;i++){

            string ar;
            cin >> ar;
            double in;
            scanf("%lf",&in);

            mp[ar] = i;
            cost[i] = in;
            mpd[i] = ar;
        }

        int p;
        scanf("%d",&p);

        while(p--){

            string ar , br;
            double in;

            cin >> ar >> br;
            scanf("%lf",&in);

            int u = mp[ar];
            int v = mp[br];

            in*=2;

            edges[u].push_back(make_pair(v , in));
            edges[v].push_back(make_pair(u , in));
        }

        printf("Map #%d\n",++m);
        int q;
        scanf("%d",&q);

        for(int i=0;i<q;i++){

            string ar , br;
            double in;

            cin >> ar >> br;
            scanf("%lf",&in);

            int st = mp[ar];
            int en = mp[br];

            for(int i=0;i<=n;i++){dis[i] = INF;parent[i] = i;}

            ans.clear();

            Dijkstra(st);

            double need = dis[en] / in;
            need += need*.10;

            printf("Query #%d\n",i+1);

            Find(en);

            int si = ans.size();
            reverse(ans.begin() , ans.end());

            for(int i=0;i<si;i++){

                if(i!=0)cout << " ";
                cout << mpd[ans[i]];
            }
            printf("\n");

            printf("Each passenger has to pay : %.2f taka\n",need);
        }
    }
    return 0;
}
