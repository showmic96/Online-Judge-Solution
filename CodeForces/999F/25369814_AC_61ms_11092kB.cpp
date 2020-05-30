// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;

int dp[505][5005] , n , k;
int c[MAX] , v[MAX] , j[MAX];

int f(int now , int tot)
{
    if(now<=0||tot<=0)return 0;
    if(dp[now][tot]!=-1)return dp[now][tot];
    int value = 0;
    for(int i=1;i<=min(k , tot);i++){
        value = max(value , f(now-1 , tot-i)+j[i-1]);
    }
    return dp[now][tot] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for(int i=0;i<n*k;i++){
        int in;
        cin >> in;
        c[in]++;
    }
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        v[in]++;
    }
    for(int i=0;i<k;i++){
        cin >> j[i];
    }
    memset(dp , -1 , sizeof(dp));
    int ans = 0;
    for(int i=0;i<MAX;i++){
        ans+=f(v[i] , c[i]);
    }
    cout << ans << endl;

    return 0;
}
