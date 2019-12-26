// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e3 + 9;
bool visited[MAX+9];
int parent[MAX+9];
int weight[MAX+9];
int beauty[MAX+9];
int sub_beauty[MAX+9];
int sub_weight[MAX+9];

int si , dp[1005][1005];

vector<int>edges[MAX+9] , v , store[MAX+9];

int Find(int x)
{
    if(parent[x]==x)return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x , int y)
{
    int px = Find(x);
    int py = Find(y);

    if(px!=py){

        //if(beauty[px]<beauty[py])swap(px , py);

        parent[py] = px;
        weight[px]+=weight[py];
        beauty[px]+=beauty[py];
    }
}

int f(int i , int w)
{
    if(i==si){

        return 0;
    }

    if(dp[i][w]!=-1)return dp[i][w];

    int value = f(i+1 , w);

    int si = store[v[i]].size();

    if(w-weight[Find(v[i])]>=0){

        value = max(value , f(i+1 , w-weight[Find(v[i])])+beauty[Find(v[i])]);
    }

    for(int j=0;j<si;j++){

        if(w-sub_weight[store[v[i]][j]]>=0){

            value = max(value , f(i+1 , w-sub_weight[store[v[i]][j]])+sub_beauty[store[v[i]][j]]);
        }
    }

    return dp[i][w] = value;
}

int main(void)
{

    memset(dp , -1 , sizeof(dp));

    int n , m , w;
    scanf("%d %d %d",&n , &m, &w);

    for(int i=0;i<=n;i++)parent[i] = i;

    for(int i=1;i<=n;i++){

        scanf("%d",&weight[i]);
        sub_weight[i] = weight[i];
    }

    for(int i=1;i<=n;i++){

        scanf("%d",&beauty[i]);
        sub_beauty[i] = beauty[i];
    }

    for(int i=0;i<m;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        Union(in1 , in2);
    }

    for(int i=1;i<=n;i++){

        if(parent[i]==i){

            v.push_back(i);
        }

        store[Find(i)].push_back(i);
    }

    si = v.size();

    printf("%d\n",f(0 , w));

    return 0;
}
