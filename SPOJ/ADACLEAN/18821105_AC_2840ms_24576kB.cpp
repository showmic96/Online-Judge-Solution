// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll p1 = 313 , MOD1 = 1e9+7 , p2 = 43 , MOD2 = 1e9+9;

map<pair<ll , ll> , ll>mp;
pair<ll , ll> value[100005];

void get_hash(string ar)
{
    ll now1 = 1 , hsh1 = 0 , now2 = 1 , hsh2 = 0;
    for(int i=0;i<ar.size();i++){
        hsh1 = hsh1 + now1*(ar[i] - 'a');
        hsh2 = hsh2 + now2*(ar[i]-'a');
        now1*=p1;
        now2*=p2;
        now1%=MOD1;
        now2%=MOD2;
        hsh1%=MOD1;
        hsh2%=MOD2;
        value[i] = {hsh1 , hsh2};
    }
}
ll BM(ll a , ll b , ll M)
{
    if(b==0)return 1%M;
    ll x = BM(a , b/2 , M);
    x = (x*x)%M;
    if(b%2==1)x = (x*a)%M;
    return x;
}

vector<string>v;
ll pw1[100005] , pw2[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    pw1[0] = 1;
    for(int i=1;i<=100000;i++){
        pw1[i] = pw1[i-1]*p1;
        pw1[i]%=MOD1;
    }
    pw2[0] = 1;
    for(int i=1;i<=100000;i++){
        pw2[i] = pw2[i-1]*p2;
        pw2[i]%=MOD2;
    }
    while(t--){
        ll n , k , ans = 0;
        cin >> n >> k;
        string ar;
        cin >> ar;
        get_hash(ar);
        mp.clear();
        for(int i=0;i<ar.size();i++){
            int t = i+k-1;
            if(t>=ar.size())break;
            if(i==0){
                mp[value[t]] = 1;
                ans++;
            }
            else{

                ll t1 = (((value[t].first-value[i-1].first)%MOD1)+MOD1)%MOD1;
                ll temp1 = t1*BM(pw1[i] , MOD1-2 , MOD1);
                temp1%=MOD1;
                ll t2 = (((value[t].second-value[i-1].second)%MOD2)+MOD2)%MOD2;
                ll temp2 = t2*BM(pw2[i] , MOD2-2 , MOD2);
                temp2%=MOD2;
                if(mp.find({temp1 , temp2})==mp.end()){
                    ans++;
                    mp[{temp1 , temp2}] = 1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
