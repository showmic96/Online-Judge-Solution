// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp1[1005][1005] , dp2[1005][1005] , dp3[1005][1005] , dp4[1005][1005] , ar[1005][1005];
int n , m;

ll f1(int i , int j)
{
    if(i==0&&j==0)return ar[i][j];
    if(i<0||j<0)return -1e18;
    if(i>=n||j>=m)return -1e18;

    if(dp1[i][j]!=-1)return dp1[i][j];

    ll value = -1e18;

    value = max(value , f1(i-1 , j)+ar[i][j]);
    value = max(value , f1(i , j-1)+ar[i][j]);

    return dp1[i][j] = value;
}

ll f2(int i , int j)
{
    if(i==0&&j==m-1)return ar[i][j];
    if(i<0||j<0)return -1e18;
    if(i>=n||j>=m)return -1e18;

    if(dp2[i][j]!=-1)return dp2[i][j];

    ll value = -1e18;

    value = max(value , f2(i-1 , j)+ar[i][j]);
    value = max(value , f2(i , j+1)+ar[i][j]);

    return dp2[i][j] = value;
}

ll f3(int i , int j)
{
    if(i==n-1&&j==0)return ar[i][j];
    if(i<0||j<0)return -1e18;
    if(i>=n||j>=m)return -1e18;

    if(dp3[i][j]!=-1)return dp3[i][j];

    ll value = -1e18;

    value = max(value , f3(i+1 , j)+ar[i][j]);
    value = max(value , f3(i , j-1)+ar[i][j]);

    return dp3[i][j] = value;
}

ll f4(int i , int j)
{
    if(i==n-1&&j==m-1)return ar[i][j];
    if(i<0||j<0)return -1e18;
    if(i>=n||j>=m)return -1e18;

    if(dp4[i][j]!=-1)return dp4[i][j];

    ll value = -1e18;

    value = max(value , f4(i+1 , j)+ar[i][j]);
    value = max(value , f4(i , j+1)+ar[i][j]);

    return dp4[i][j] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    memset(dp1 , -1 , sizeof(dp1));
    memset(dp2 , -1 , sizeof(dp2));
    memset(dp3 , -1 , sizeof(dp3));
    memset(dp4 , -1 , sizeof(dp4));

    cin >> n >> m;

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++)cin >> ar[i][j];
    }

    ll ans = -1e18;

    for(int i=1;i<n-1;i++){

        for(int j=1;j<m-1;j++){

            ans = max(ans , f1(i , j-1)+f2(i-1 , j)+f3(i+1 , j)+f4(i , j+1));
            ans = max(ans , f1(i-1 , j)+f2(i , j+1)+f3(i , j-1)+f4(i+1 , j));
        }
    }

    cout << ans << endl;

    return 0;
}
