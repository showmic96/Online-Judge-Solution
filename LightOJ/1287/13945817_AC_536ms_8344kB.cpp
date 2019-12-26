// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int n , m;
vector<pair<int , double> > edges[15];

bool vis[16][(1<<15)+5];
double dp[16][(1<<15)+5];
int now[16][(1<<15)+5];

bool Check(int n , int pos)
{
    return n&(1<<pos);
}
int Set(int n , int pos)
{
    return n|(1<<pos);
}

double f(int i , int mask)
{
    if(mask==(1<<n)-1){

        return 0;
    }

    if(vis[i][mask]==true)return dp[i][mask];
    vis[i][mask] = true;

    double counter = 0 , value = 0;

    for(int j=0;j<edges[i].size();j++){

        if(Check(mask , edges[i][j].first)==false){

            if(now[edges[i][j].first][Set(mask , edges[i][j].first)]==0)continue;
            value+=f(edges[i][j].first , Set(mask , edges[i][j].first))+edges[i][j].second;
            counter++;
        }
    }

    value+=5;
    return dp[i][mask] = value/counter;
}

int f2(int i , int mask)
{
    if(mask==(1<<n)-1){

        return 1;
    }

    if(now[i][mask]!=-1)return now[i][mask];

    int value = 0;

    for(int j=0;j<edges[i].size();j++){

        if(Check(mask , edges[i][j].first)==false){

            value = max(value , f2(edges[i][j].first , Set(mask , edges[i][j].first)));
        }
    }

    return now[i][mask] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d",&n , &m);

        memset(vis , false ,sizeof(vis));
        memset(now , -1 , sizeof(now));

        for(int i=0;i<=n;i++)edges[i].clear();

        for(int i=0;i<m;i++){

            int in1 ,in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);

            edges[in1].push_back(make_pair(in2 , in3));
            edges[in2].push_back(make_pair(in1 , in3));
        }

        int possible = f2(0 , 1);

        if(possible==0)printf("Case %d: 0\n",++c);
        else printf("Case %d: %.14f\n",++c , f(0 , 1));
    }
    return 0;
}
