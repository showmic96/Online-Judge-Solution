// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2e5+9;

ll dp[MAX+9][2];
bool visited[MAX+9][2];
int n;
vector<int>v;

ll f(int i , int now)
{
    if(i>n)return 0;
    if(i<=0)return 0;

    if(visited[i][now]==true){

        if(dp[i][now]==-1)return 1e18;
        return dp[i][now];
    }

    visited[i][now] = true;

    ll value = 0;

    if(now==0){

        value = f(i+v[i] , 1-now)+v[i];
    }

    else{

        value = f(i-v[i] , 1-now)+v[i];
    }

    return dp[i][now] = value;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));
    memset(visited , false , sizeof(visited));

    v.push_back(0);
    v.push_back(1);

    scanf("%d",&n);

    for(int i=1;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    for(int i=1;i<n;i++){

        v[1] = i;

        dp[1][0] = -1;
        dp[1][1] = -1;
        visited[1][0] = false;
        visited[1][1] = false;

        ll ans = f(1 , 0);

        if(ans>1e17)ans = -1;

        printf("%lld\n",ans);
    }

    return 0;
}
