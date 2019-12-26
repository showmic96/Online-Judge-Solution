// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll>v1 , v2;
int n;
ll dp[100005][2];

ll f(int i , int now)
{
    if(i==n)return 0;
    if(dp[i][now]!=-1)return dp[i][now];
    ll value = 0;
    if(now==0){
        value = f(i+1 , now);
        value = max(value , f(i+1 , now^1)+v1[i]);
    }
    else{
        value = f(i+1 , now);
        value = max(value , f(i+1 , now^1)+v2[i]);
    }
    return dp[i][now] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){
        ll in;
        cin >> in;
        v1.push_back(in);
    }
    for(int i=0;i<n;i++){
        ll in;
        cin >> in;
        v2.push_back(in);
    }
    memset(dp , -1 , sizeof(dp));
    cout << max(f(1 , 1)+v1[0] , f(1 , 0)+v2[0]) << endl;

    return 0;
}
