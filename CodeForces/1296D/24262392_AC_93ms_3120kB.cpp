// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , a , b , k;
    cin >> n >> a >> b >> k;
    vector<ll>v;
    for(int i=0;i<n;i++){
        ll in;
        cin >> in;
        ll req = (in+a+b-1LL)/(a+b);
        in-=(req-1LL)*b;
        ll req2 = (in+a-1LL)/a;
        v.push_back(req2-req);
    }
    sort(v.begin() , v.end());
    ll tot = 0 , cnt = 0;
    for(int i=0;i<v.size();i++){
        if(tot+v[i]<=k){
            cnt++;
            tot+=v[i];
        }
    }
    cout << cnt << endl;
    return 0;
}
