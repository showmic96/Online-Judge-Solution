// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll INF = 1234567891011121314;

struct node{

    string name;
    int x , y , z;
}ar[66];

char x[66];
double dis[66];
vector<pair<ll , double > > edges[66];

double f(double x1 , double y1 , double x2 , double y2 , double x3 , double y3)
{
    double d = (x1-y1)*(x1-y1);
    d+=(x2-y2)*(x2-y2);
    d+=(x3-y3)*(x3-y3);

    d = sqrt(d);

    return d;
}

void dijkstra(int u)
{
    priority_queue<pair<double , ll > >pq;
    dis[u] = 0;
    pq.push(make_pair(0 , u));

    while(!pq.empty()){

        u = pq.top().second;
        pq.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            int v = edges[u][i].first;
            double c = edges[u][i].second;

            if(dis[v]>dis[u]+c){

                dis[v] = dis[u]+c;

                pq.push(make_pair(-dis[v] , v));
            }
        }
    }
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        map<string , int>mp;

        for(int i=0;i<=n;i++)edges[i].clear();

        for(int i=0;i<n;i++){

            scanf("%s",&x);
            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);

            string temp(x);

            ar[i].name = temp;ar[i].x = in1;ar[i].y = in2;ar[i].z = in3;

            mp[temp] = i;
        }

        int m;
        scanf("%d",&m);

        for(int i=0;i<m;i++){

            scanf("%s",&x);

            string t1(x);

            scanf("%s",&x);

            string t2(x);

            edges[mp[t1]].push_back(make_pair(mp[t2] , 0));
        }

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                double d = f(ar[i].x , ar[j].x , ar[i].y , ar[j].y , ar[i].z , ar[j].z);

                edges[i].push_back(make_pair(j , d));
                edges[j].push_back(make_pair(i , d));
            }
        }

        int q;
        scanf("%d",&q);

        printf("Case %d:\n",++c);

        while(q--){

            scanf("%s",&x);

            string t1(x);

            scanf("%s",&x);

            string t2(x);

            for(int i=0;i<=n;i++)dis[i] = INF;

            dijkstra(mp[t1]);

            cout << "The distance from " << t1 << " to " << t2 << " is " << (ll)(dis[mp[t2]]+0.5) << " parsecs." << endl;
        }
    }
    return 0;
}
