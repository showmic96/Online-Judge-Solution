// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll , ll > >v1 , v2;
ll n , r , tot = 0;
ll dp[102][30002*2];

bool cmp(pair<ll , ll> A , pair<ll , ll> B)
{
    return A.first+A.second>B.first+B.second;
}

ll f(int i , int r)
{
    if(i==v2.size())return 0;
    if(dp[i][r]!=-1)return dp[i][r];
    ll value = f(i+1 , r);
    if(r+v2[i].second>=0&&r>=v2[i].first)value = max(value , f(i+1 , r+v2[i].second)+1);
    return dp[i][r] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> r;
    for(int i=0;i<n;i++){
        ll in1 , in2;
        cin >> in1 >> in2;
        if(in2>=0)v1.push_back({in1 , in2});
        else v2.push_back({in1 , in2});
    }
    sort(v1.begin(), v1.end());
    for(int i=0;i<v1.size();i++){
        if(v1[i].first<=r)r+=v1[i].second , tot++;
    }
    sort(v2.begin(), v2.end() , cmp);
    memset(dp , -1 , sizeof(dp));
    cout << tot+f(0 , r) << endl;

    return 0;
}
