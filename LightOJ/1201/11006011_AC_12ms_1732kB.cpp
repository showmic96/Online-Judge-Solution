// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1005;

vector<int>edges[MAX+9];
bool visited[MAX+9][2];
bool v[MAX];

ll dp[MAX][2];

ll f(int i, int pre , int parent)
{

    if(visited[i][pre]==true)return dp[i][pre];
    visited[i][pre] = true;

    dp[i][pre] = 0;
    v[i] = true;

    ll value = 0;

    if(pre==0){

        int si = edges[i].size();

        for(int j=0;j<si;j++){

            if(edges[i][j]==parent)continue;

            value+=f(edges[i][j] , 0 , i);
        }

        ll temp = 1;

        for(int j=0;j<si;j++){

            if(edges[i][j]==parent)continue;

            temp+=f(edges[i][j] , 1 , i);
        }


        value = max(value , temp);
    }

    if(pre==1){

        int si = edges[i].size();

        for(int j=0;j<si;j++){

            if(edges[i][j]==parent)continue;

            value+=f(edges[i][j] , 0 , i);
        }
    }

    return dp[i][pre] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , m;
        scanf("%d %d",&n, &m);

        for(int i=0;i<=n;i++){

            edges[i].clear();
            visited[i][0] = false;
            visited[i][1] = false;
        }

        memset(v , false , sizeof(v));


        for(int i=0;i<m;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);

            edges[in1].push_back(in2);
            edges[in2].push_back(in1);
        }

        ll value = 0;

        for(int i=1;i<=n;i++){

            if(v[i]==false){

                value+=f(i , 0 , -100);
            }
        }

        printf("Case %d: %lld\n",++c, value);
    }
    return 0;
}
