// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 300000+9;
vector<int>edges[MAX+9];

int L[MAX] , P[MAX][22] , T[MAX];
bool vis[MAX];

void dfs(int from , int u , int dep)
{
    queue<int>current;
    vis[from] = true;
    current.push(from);
    T[u] = from;
    L[u] = 0;

    while(!current.empty()){

        u = current.front();
        current.pop();

        for(auto v : edges[u]){

            if(vis[v]==false){

                vis[v] = true;
                T[v] = u;
                L[v] = L[u]+1;
                current.push(v);
            }
        }
    }
}

int lca_query(int N , int p , int q)
{
    int log = 1;
    if(L[p]<L[q])swap(p , q);
    while(true){

        int next = log+1;
        if((1<<next)>L[p])break;
        log++;
    }

    for(int i=log;i>=0;i--){

        if(L[p]-(1<<i)>=L[q])p = P[p][i];
    }
    if(p==q)return p;

    for(int i=log;i>=0;i--){

        if(P[p][i]!=-1&&P[p][i]!=P[q][i]){

            p = P[p][i] , q = P[q][i];
        }
    }
    return T[p];
}

void lca_init(int N)
{
    memset(P , -1 , sizeof(P));
    for(int i=1;i<=N;i++){

        P[i][0] = T[i];
    }
    for(int j=1;(1LL<<j)<=N;j++){

        for(int i=1;i<=N;i++){

            if(P[i][j-1]!=-1){

                P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }
}

int main(void)
{
    int n;
    scanf("%d",&n);

    memset(vis , false , sizeof(vis));

    for(int i=0;i<n-1;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }

    dfs(1 , 1 , 0);
    lca_init(n);
    ll sum = 0;

    for(int i=1;i<=n;i++){

        for(int j=2*i;j<=n;j+=i){

            int temp = lca_query(n , i , j);
            sum+=L[i]+L[j]-2LL*L[temp]+1LL;

        }
    }

    printf("%lld\n",sum);

    return 0;
}
