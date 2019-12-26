// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3+9;
vector<int>edges[MAX+9];
int n , k;

int dfs(int u , int p)
{
    int value = 1;

    int si = edges[u].size();

    vector<int>v;

    for(int i=0;i<si;i++){

        if(edges[u][i]!=p){

            v.push_back(dfs(edges[u][i] , u));
        }
    }

    if(v.size()<k)return 1;
    sort(v.begin() , v.end());

    int counter = 0;

    for(int i=v.size()-1;i>=0;i--){

        value+=v[i];
        counter++;
        if(counter==k)break;
    }

    return value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d",&n , &k);

        for(int i=0;i<=n;i++)edges[i].clear();

        for(int i=0;i<n-1;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);

            edges[in1].push_back(in2);
            edges[in2].push_back(in1);
        }

        printf("Case %d: %d\n",++c , dfs(1 , -1));
    }
    return 0;
}
