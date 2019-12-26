// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[1005][5005][2];
int n;
vector<int>v;

int f(int i , int l , int pre)
{
    if(i==n-1)return 0;

    if(dp[i][l][pre]!=-1)return dp[i][l][pre];

    int value = 0;

    if(pre==1){

        value = f(i+1 , l , 0);
    }
    else{

        value = f(i+1 , l , 0);

        if(v[i+1]-v[i]<=l)value = max(value , f(i+1 , l-(v[i+1]-v[i]) , 1)+2);
    }

    return dp[i][l][pre] = value;
}

int main(void)
{
    int t ,c = 0;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));

        int m;
        scanf("%d %d",&n,&m);
        v.clear();

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        printf("Case %d: %d\n",++c , f(0 , m ,0));
    }
    return 0;
}
