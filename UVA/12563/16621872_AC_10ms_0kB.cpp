// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , t , counter;
int dp[10005];
vector<int>v;

int main(void)
{
    int tc , c = 0;
    scanf("%d",&tc);
    while(tc--){

        v.clear();
        scanf("%d %d",&n , &t);
        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        memset(dp , -1 , sizeof(dp));
        dp[0] = 0;

        for(int j=0;j<n;j++){

            for(int i=10000;i>=1;i--){

                if(i>=v[j]&&dp[i-v[j]]!=-1)dp[i] = max(dp[i] , dp[i-v[j]]+1);
            }
        }

        int ans = 0 , mx = 0;

        for(int i=t-1;i>=1;i--){

            if(dp[i]>mx){

                mx = dp[i];
                ans = i;
            }
        }

        printf("Case %d: %d %d\n",++c , mx+1 , ans+678);
    }
    return 0;
}
