// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e3+9;

int n , m , b , p;
vector<pair<int , int> > edges[MAX+9];
int dis[MAX+9];
priority_queue<pair<int , int> > pq;

void Dijkstra()
{
    while(!pq.empty()){

        int u = pq.top().second;
        int c1 = pq.top().first;
        pq.pop();

        for(int i=0;i<edges[u].size();i++){

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
    while(scanf("%d %d %d %d",&n , &m , &b , &p)==4){

        for(int i=0;i<=n;i++){

            edges[i].clear();
            dis[i] = 1e9;
        }

        for(int i=0;i<m;i++){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);
            edges[in1].push_back(make_pair(in2 , in3));
            edges[in2].push_back(make_pair(in1 , in3));
        }

        vector<int>v;

        for(int i=0;i<b;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        for(int i=0;i<p;i++){

            int in;
            scanf("%d",&in);
            pq.push(make_pair(0 , in));
            dis[in] = 0;
        }

        Dijkstra();

        int mx = 0;
        set<int>st;

        for(int i=0;i<b;i++){

            if(dis[v[i]]>mx){

                st.clear();
                mx = dis[v[i]];
                st.insert(v[i]);
            }
            else if(dis[v[i]]==mx){

                st.insert(v[i]);
            }
        }

        if(dis[*st.begin()]==1e9)printf("%d *\n",st.size());
        else printf("%d %d\n",st.size() , dis[*st.begin()]);
        set<int>::iterator it = st.begin();
        printf("%d",*it);

        for(it++;it!=st.end();it++){

            printf(" %d",*it);
        }
        printf("\n");
    }

    return 0;
}
