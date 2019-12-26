// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e3;
vector<int>edges[MAX+9];
int level[MAX+9];
int counter;

void dfs(int u , int p)
{
    if(level[u]==0)level[u] = 1;

    int si = edges[u].size();

    for(int i=0;i<si;i++){

        if(edges[u][i]!=p){

            dfs(edges[u][i] , u);
            level[u]+=level[edges[u][i]];
        }
    }

    //cout << u << " " << level[u] << endl;

    if(level[u]>0)if(level[u]%2==0&&u!=1)counter++,level[u] = 0;
}

int main(void)
{
    memset(level , 0 , sizeof(level));

    int n , m;
    scanf("%d %d",&n , &m);
    while(m--){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);

        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }

    counter = 0;

    dfs(1 , -1);

    printf("%d\n",counter);

    return 0;
}
