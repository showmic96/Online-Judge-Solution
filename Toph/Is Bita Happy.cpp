// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[35][2][2][2] , pw[35];
ll a , k , l , r;
vector<ll>v;
string ans[] = {"Even" , "Odd"};

void make(ll x)
{
    memset(dp , -1 , sizeof(dp));
    v.clear();
    while(x){
        v.push_back(x%2);
        x/=2;
    }
    if(v.size()==0)v.push_back(0);
    reverse(v.begin(), v.end());
}

ll f(int i , int smaller , int tot , int now)
{
    if(i==v.size()){
        if(now==1)return tot%2;
        return 0;
    }
    if(dp[i][smaller][tot][now]!=-1)return dp[i][smaller][tot][now];
    int lim = v[i];
    if(smaller)lim = 1;
    ll value = 0;
    if(i==v.size()-k-1){
        if(lim==1)value+=f(i+1 , smaller, 1 , 1);
    }
    else{
        for(ll j=0;j<=lim;j++){
            value+=f(i+1 , smaller||(j<lim) , j , now);
        }
    }
    return dp[i][smaller][tot][now] = value%2;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> a >> k >> l >> r;
        if((a&(1<<k))==0){
            cout << ans[0] << endl;
            continue;
        }
        else{
            make(l-1);
            ll ans1 = f(0 , 0 , 0 , 0);
            make(r);
            ll ans2 = f(0 , 0 , 0 , 0);
            cout << ans[(ans2-ans1+2)%2] << endl;
        }
    }

    return 0;
}