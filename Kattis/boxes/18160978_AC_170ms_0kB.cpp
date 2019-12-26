// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 200005+9;
vector<int>edges[MAX] , v;

int sz[MAX] , tot[MAX];
int st[MAX] , en[MAX] , now = 1;

void dfs(int u , int par = -1)
{
    sz[u] = 1;
    st[u] = now++;
    for(auto v : edges[u]){

        if(v!=par){

            dfs(v , u);
            sz[u]+=sz[v];
        }
    }
    en[u] = now;
}

bool cmp(int a , int b)
{
    return st[a] < st[b];
}

int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
        edges[in].push_back(i+1);
    }
    for(int i=0;i<n;i++){

        if(v[i]==0)dfs(i+1);
    }

    int q;
    scanf("%d",&q);
    while(q--){

        int m;
        scanf("%d",&m);
        vector<int>temp;
        ll counter = 0;
        for(int i=0;i<m;i++){

            int in;
            scanf("%d",&in);
            temp.push_back(in);
        }

        sort(temp.begin() , temp.end() , cmp);
        int last = -1;

        for(int i=0;i<m;i++){

            if(st[temp[i]]>=last){
                counter+=sz[temp[i]];
                last = en[temp[i]];
            }
        }

        printf("%lld\n",counter);
    }
    return 0;
}
