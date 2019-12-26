// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll ar[15];
vector<string>v;
ll MOD = 998244353;

ll f1(int idx , int pos)
{
    ll now = 0;
    for(int i=0 , k=v[idx].size()-1;i<v[idx].size();i++,k--){
        if(k<pos)now*=100;
        else now*=10;
        now+=v[idx][i]-'0';
    }
    return now;
}
ll f2(int idx , int pos)
{
    ll now = 0;
    for(int i=0 , k=v[idx].size()-1;i<v[idx].size();i++,k--){
        if(k+1<pos)now*=100;
        else now*=10;
        now+=v[idx][i]-'0';
    }
    return now*10LL;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        v.push_back(s);
        ar[s.size()]++;
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<11;j++){
            ll temp = f1(i , j)%MOD;
            ans+=(temp*ar[j])%MOD;
            ans%=MOD;
        }
        for(int j=0;j<11;j++){
            ll temp = f2(i , j)%MOD;
            ans+=(temp*ar[j])%MOD;
            ans%=MOD;
        }
    }
    cout << ans << endl;

    return 0;
}
