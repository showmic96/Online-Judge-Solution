// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+10;

vector<int>edges[MAX];
bool isVisited[MAX];

int hi = 0;
int n , m;

void setUp(int n)
{
    for(int i=0;i<=n;i++){

        edges[i].clear();
        isVisited[i] = false;
    }
}

void dfs(int i , int current)
{

    //if(isVisited[i]==true)return;

    isVisited[i] = true;

    hi = max(hi , current);

    int si = edges[i].size();

    for(int j=0;j<si;j++){

        dfs(edges[i][j] , current+1);
    }

}


int main(void)
{
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);//cin >> t;
    map<int , int >mp;

    for(int i=0;i<t;i++){
        scanf("%d %d",&n,&m);//cin >> n >> m;
        mp.clear();
        hi = 0;

        setUp(n);

        while(m--){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);//cin >> in1 >> in2;
            edges[in1].push_back(in2);
            mp[in2] = 1;
        }

        for(int i=1;i<=n;i++){

            if(mp[i]==0)dfs(i , 1);
        }

        printf("Case %d: %d\n",i+1 , hi);
    }
    return 0;
}
