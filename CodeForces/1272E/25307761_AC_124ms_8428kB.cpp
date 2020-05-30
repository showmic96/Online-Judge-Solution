// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX =  2e5+9;
int n , dp[MAX];
vector<int>v;
vector<int>edges[MAX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    memset(dp , -1 , sizeof(dp));

    cin >> n;
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        v.push_back(in);
    }
    queue<int>current;
    for(int i=0;i<n;i++){
        int l = i-v[i];
        int r = i+v[i];
        if(l>=0&&v[i]%2!=v[l]%2)dp[i] = 1;
        if(r<n&&v[i]%2!=v[r]%2)dp[i] = 1;
        if(l>=0)edges[l].push_back(i);
        if(r<n)edges[r].push_back(i);
        if(dp[i]==1)current.push(i);
    }
    while(!current.empty()){
        int u = current.front();
        current.pop();
        for(auto v:edges[u]){
            if(dp[v]==-1){
                dp[v] = dp[u] + 1;
                current.push(v);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << dp[i] << " ";
    }

    return 0;
}
