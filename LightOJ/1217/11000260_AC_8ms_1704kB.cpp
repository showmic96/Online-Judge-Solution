// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int>v;

ll dp[1005][2];

ll f(int i , int first)
{
    if(i==n-1){

        if(first==0){

            return v[n-1];
        }

        return 0;
    }

    if(i>=n)return 0;

    if(dp[i][first]!=-1)return dp[i][first];

    ll value = 0;

    if(i==0){

        value = f(i+1 , first);
        value = max(f(i+2 , 1)+v[0] , value);
    }

    else{

        value = f(i+1 , first);
        value = max(f(i+2, first)+v[i] , value);
    }

    return dp[i][first] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        v.clear();

        scanf("%d",&n);
        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        memset(dp , -1 , sizeof(dp));

        printf("Case %d: %lld\n",++c, f(0 , 0));
    }
    return 0;
}
