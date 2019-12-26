// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1234;

int n , k , m;
map<int , int>mp;
bool isVisited[MAX];
vector<int>edges[MAX];

void setUp()
{
    for(int i=0;i<MAX;i++)edges[i].clear();
}

void dfs(int i)
{
    if(isVisited[i]==true)return ;
    isVisited[i] = true;
    mp[i]++;

    int si = edges[i].size();

    for(int j=0;j<si;j++){

        dfs(edges[i][j]);
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){

        setUp();
        mp.clear();
        scanf("%d %d %d",&k , &n , &m);

        vector<int>start;

        for(int j=0;j<k;j++){

            int in;
            scanf("%d",&in);
            start.push_back(in);
        }

        for(int j=0;j<m;j++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            edges[in1].push_back(in2);
        }

        for(int j=0;j<k;j++){

            memset(isVisited , false , sizeof(isVisited));

            dfs(start[j]);
        }

        int counter = 0;

        for(int j=1;j<=n;j++)if(mp[j]==k)counter++;

        printf("Case %d: %d\n",i+1, counter);
    }

    return 0;
}
