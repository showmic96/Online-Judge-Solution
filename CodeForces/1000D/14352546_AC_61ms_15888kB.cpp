// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 998244353;
ll dp[1005][1005][2];

int n;
vector<int>v;

ll f(int i , int rem , int taken)
{
    if(rem<0)return 0;
    if(i==n){

        if(rem==0&&taken==1)return 1;
        return 0;
    }
    if(dp[i][rem][taken]!=-1)return dp[i][rem][taken];

    ll value = f(i+1 , rem , taken);
    if(rem==0&&v[i]>0&&v[i]<=n)value+=f(i+1 , v[i] , 1);
    value+=f(i+1 , rem-1 , 1);

    return dp[i][rem][taken] = value%MOD;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){

        int in;
        cin >> in;
        v.push_back(in);
    }

    memset(dp , -1 , sizeof(dp));
    cout << f(0 , 0 , 0) << endl;

    return 0;
}
