// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

struct s{

    int fr[26];
    s(){

        memset(fr , 0 , sizeof(fr));
    }

}city[10005];

vector<pair<int , int> > edges[10005];
int dis[10005];

void Dijkstra(int st)
{
    for(int i=0;i<=10000;i++)dis[i] = 1e9;
    priority_queue<pair< int , int> > pq;
    dis[st] = 0;
    pq.push(make_pair(0 , st));

    while(!pq.empty()){

        int u = pq.top().second;
        pq.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            int v = edges[u][i].first;
            int c = edges[u][i].second;

            if(dis[v]>dis[u]+c){

                dis[v] = dis[u]+c;
                pq.push(make_pair(-dis[v] , v));
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n , m;
    cin >> n >> m;

    for(int i=1;i<=n;i++){

        string ar;
        cin >> ar;

        int si = ar.size();

        for(int j=0;j<si;j++){

            if(ar[j]>='A'&&ar[j]<='Z')ar[j]+=32;

            city[i].fr[ar[j]-'a'] = 1;
        }
    }

    for(int i=0;i<m;i++){

        int in1 , in2;
        cin >> in1 >> in2;

        int counter = 0;

        for(int j=0;j<26;j++){

            if(city[in1].fr[j]==city[in2].fr[j]&&city[in1].fr[j]==1)counter++;
        }

        edges[in1].push_back(make_pair(in2 , counter));
        edges[in2].push_back(make_pair(in1 , counter));
    }

    int st , en;
    cin >> st >> en;

    Dijkstra(st);

    cout << dis[en] << endl;

    return 0;
}
