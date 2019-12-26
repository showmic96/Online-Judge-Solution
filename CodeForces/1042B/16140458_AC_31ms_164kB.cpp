// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<pair<int , string> > v;
int dp[1005][8];

int f(int i , int mask)
{
    if(i==n){

        if(mask==7)return 0;
        return 1e9;
    }

    if(dp[i][mask]!=-1)return dp[i][mask];
    int value = f(i+1 , mask);

    int temp = mask;
    for(int j=0;j<v[i].second.size();j++){

        temp = temp|(1<<(v[i].second[j]-'A'));
    }

    value = min(value , f(i+1 , temp)+v[i].first);
    return dp[i][mask] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){

        int in;
        string ar;
        cin >> in >> ar;
        v.push_back(make_pair(in  , ar));
    }

    memset(dp , -1 , sizeof(dp));

    int ans = f(0 , 0);
    if(ans>=1e9)ans = -1;
    cout << ans << endl;

    return 0;
}
