// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v;
int n , p;
int dp[22][1005];

int f(int i , int val)
{
    if(i==p){

        if(val==n)return 1;
        return 0;
    }
    if(dp[i][val]!=-1)return dp[i][val];
    int value = f(i+1 , val);
    if(val+v[i]<=n)value = max(value , f(i+1 , val+v[i]));
    return dp[i][val] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        v.clear();
        scanf("%d %d",&n , &p);

        for(int i=0;i<p;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        memset(dp , -1 , sizeof(dp));
        int ans = f(0 , 0);

        if(ans==1)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
