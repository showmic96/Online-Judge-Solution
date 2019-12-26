// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

vector<pair<int , int> >edges[20];
vector<int>v;
int n , m, k , dp[(1<<15)+10];

bool Check(int mask , int pos)
{
    return mask&(1<<pos);
}

int Set(int mask , int pos)
{
    return mask|(1<<pos);
}

int f(int mask)
{
    if(dp[mask]!=-1)return dp[mask];

    bool check = true;

    for(int i=0;i<k;i++){

        if(Check(mask , v[i]-1)==false)check = false;
    }

    if(check)return 0;
    int value = 1e9;

    for(int j=1;j<=n;j++){

        if(Check(mask , j-1)==true){

            for(int i=0;i<edges[j].size();i++){

                if(Check(mask , edges[j][i].first-1)==false){

                    value = min(value , f(Set(mask , edges[j][i].first-1))+edges[j][i].second);
                }
            }
        }
    }

    return dp[mask] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d %d",&n , &m ,&k);
        for(int i=0;i<=n;i++)edges[i].clear();
        memset(dp , -1 , sizeof(dp));

        for(int i=0;i<m;i++){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);
            edges[in1].push_back(make_pair(in2 , in3));
            edges[in2].push_back(make_pair(in1 , in3));
        }

        v.clear();
        for(int i=0;i<k;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        int ans = 1e9;

        for(int i=1;i<=n;i++){

            ans = min(ans , f(Set(0 , i-1)));
        }

        printf("%d\n",ans);
    }
    return 0;
}
