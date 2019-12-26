#include<bits/stdc++.h>
using namespace std;

const int MAX = 100001 , INF = (int)1e9;

int a , b;
int in1 , in2 , c , n , m , s , t;

int cost[MAX+5];
map<int,int>node_cost;
vector<pair<int , int> >node[MAX+5];
pair<int,int>temp;
long long total = 0 , total_cost;

void setUp(int start)
{
    for(int i=1;i<=MAX;i++)cost[i]=INF;
    cost[start] = 0;
}


void dijkstra(int start)
{
    priority_queue<pair<int,int> >current;

    setUp(start);

    current.push(make_pair(0 , start));

    //node_cost[0] = 0;

    int temp1 , temp2 , si;

    while(!current.empty()){

        temp1 = current.top().first;
        temp2 = current.top().second;
        current.pop();

        if(temp1>cost[temp2])continue;

        si = node[temp2].size();


        for(int i=0;i<si;i++){

            int v = node[temp2][i].first , c = node[temp2][i].second ;

            if(cost[v]>cost[temp2]+c){

                cost[v]=cost[temp2]+c;
                current.push(make_pair(-cost[v],v));

            }
        }
    }
    int ans = cost[max(s,t)];
    if(ans==INF)cout <<  "unreachable" << endl;
    else cout << ans << endl;
}

void zero()
{
    for(int i=0;i<=MAX;i++){
        node[i].clear();
    }
}

int main(void)
{

    cin >> a;
    for(int i = 0; i<a; i++){
        zero();
        cin >> n >> m >> s >> t;


        while(m--){

            cin >> in1 >> in2 >> c;

            node[in1].push_back(make_pair(in2,c));
            node[in2].push_back(make_pair(in1,c));
        }
        printf("Case #%d: ",i+1);
        dijkstra(min(s,t));
    }

    return 0;
}
