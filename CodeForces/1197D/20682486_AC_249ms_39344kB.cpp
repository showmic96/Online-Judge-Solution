// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[300005][11];
ll n , m , k;
vector<ll>v;

ll f(int i , int temp)
{
    int t = temp;
    if(i==n)return 0;
    if(dp[i][t]!=-1)return dp[i][t];
    ll value = 0;
    temp = (temp+1)%m;
    if(t==0){
        value = max(value , f(i+1 , temp)+v[i]-k);
    }
    else{
        value = max(value , f(i+1 , temp)+v[i]);
    }
    return dp[i][t] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        ll in;
        cin >> in;
        v.push_back(in);
    }
    memset(dp , -1 , sizeof(dp));
    ll mx = 0;
    for(int i=0;i<n;i++){
        mx = max(mx , f(i , 0));
    }
    cout << mx << endl;

    return 0;
}
