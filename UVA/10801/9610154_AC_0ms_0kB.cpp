// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int n , k;
int dLift[111];

vector<pair< pair<int , int>  , int> > edges[111];
vector<int>zero;

int dis[111][10];

void Dijkstra()
{
    priority_queue< pair< pair<int , int>  , int>  , vector< pair< pair<int , int>  , int> > , greater < pair< pair<int , int>  , int> > > pq;

    int si = zero.size();

    for(int i=0;i<si;i++){

        dis[0][zero[i]] = 0;

        pq.push(make_pair(make_pair(0 , 0) , zero[i]));
    }

    while(!pq.empty()){

        int u = pq.top().first.second;
        int c1 = pq.top().first.first;
        int x = pq.top().second;

        pq.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            int v = edges[u][i].first.first;
            int c = edges[u][i].first.second;
            int y = edges[u][i].second;

            if(x==y){

                if(dis[v][x]>dis[u][x]+c){

                    dis[v][x] = dis[u][x]+c;
                    pq.push(make_pair(make_pair(dis[v][x] , v) , y));
                }
            }

            else{

                if(dis[v][y]>dis[u][x]+c+60){

                    dis[v][y] = dis[u][x]+c+60;

                    pq.push(make_pair(make_pair(dis[v][x] , v) , y));
                }
            }
        }
    }
}

int main(void)
{
    while(scanf("%d %d",&n , &k)==2){

        for(int i=0;i<=100;i++){

            edges[i].clear();

            for(int j=0;j<=5;j++){

                dis[i][j] = 12345678;
            }
        }

        for(int i=0;i<n;i++)scanf("%d",&dLift[i]);

        scanf("\n");
        zero.clear();

        for(int i=0;i<n;i++){

            string ar;
            getline(cin , ar);
            int temp;
            vector<int>v;

            stringstream ss(ar);

            while(ss >> temp){

                v.push_back(temp);
                if(temp==0)zero.push_back(i);
            }

            int si = v.size();

            for(int j=0;j<si;j++){


                for(int k=j+1;k<si;k++){

                    edges[v[j]].push_back(make_pair(make_pair(v[k] , (v[k]-v[j])*dLift[i]) , i));
                    edges[v[k]].push_back(make_pair(make_pair(v[j] , (v[k]-v[j])*dLift[i]) , i));
                }
            }
        }

        Dijkstra();

        int ans = 12345678;

        for(int i=0;i<n;i++){

            ans = min(dis[k][i] , ans);
        }

        if(ans!=12345678)printf("%d\n",ans);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
