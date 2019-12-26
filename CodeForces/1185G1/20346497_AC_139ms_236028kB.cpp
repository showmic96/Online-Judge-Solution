// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int Set(int n , int pos)
{
    return n|(1<<pos);
}
bool Check(int n , int pos)
{
    return n&(1<<pos);
}

ll dp[(1<<15)+5][4][230];
ll MOD = 1e9+7;
int n , t;
vector<pair<int , int> > v;
ll f(int mask , int pre , int tot)
{
    if(tot==t){
        return 1;
    }
    if(dp[mask][pre][tot]!=-1)return dp[mask][pre][tot];
    ll value = 0;
    for(int i=0;i<n;i++){
        if(Check(mask , i)==false&&pre!=v[i].second&&v[i].first+tot<=t){
            value+=f(Set(mask , i) , v[i].second , tot+v[i].first);
        }
    }
    return dp[mask][pre][tot] = value%MOD;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> t;
    for(int i=0;i<n;i++){
        int in1 , in2;
        cin >> in1 >> in2;
        v.push_back({in1 , in2});
    }
    memset(dp , -1 , sizeof(dp));
    cout << f(0 , 0 , 0);

    return 0;
}
