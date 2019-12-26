// In the name of Allah the Lord of the worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 5e5 + 100;
int n , m , parent[MAX+7] , level[MAX+9];

void setUp(int n)
{
    for(int i=0;i<=n;i++){

        parent[i] = i;
        level[i] = 1;
    }
}

int Find(int x)
{
    if(x==parent[x])return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x , int y)
{
    int u = Find(x);
    int v = Find(y);

    if(u==v)return ;

    if(level[u]<level[v])swap(u , v);

    parent[v] = u;
    level[u]+=level[v];
}

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        cin >> n >> m;

        setUp(n);

        int in1 , in2;

        while(m--){

            cin >> in1 >> in2;
            Union(in1 , in2);

        }

        int mx = 0;

        for(int i=1;i<=n;i++){

            if(level[i]>mx)mx = level[i];
        }

        cout << mx << endl;
    }
    return 0;
}
