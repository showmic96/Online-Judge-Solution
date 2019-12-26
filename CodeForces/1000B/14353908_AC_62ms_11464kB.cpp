// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[100005][2][2];
vector<ll>v , store;

ll f(int i , int now , int l)
{
    if(i==store.size())return 0;

    if(dp[i][now][l]!=-1)return dp[i][now][l];

    ll value = 0;

    if(now==0){

        if(l==1){

            if(store[i]>1)value = max(value , f(i+1 , 0 , 0)+store[i]-1);
        }
        value = max(value , f(i+1 , 1 , l)+store[i]);
    }
    else{

        if(l==1){

            value = max(value , f(i+1 , 1 , 0)+store[i]-1);
        }
        value = max(value , f(i+1 , 0 , l));
    }

    return dp[i][now][l] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , m;
    cin >> n >> m;

    ll ans = 0;

    v.push_back(0);

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        v.push_back(in);
    }

    v.push_back(m);

    for(int i=0;i<v.size()-1;i++){

        store.push_back(v[i+1]-v[i]);

    }

    memset(dp , -1 , sizeof(dp));

    cout << f(0 , 0 , 1) << endl;

    return 0;
}