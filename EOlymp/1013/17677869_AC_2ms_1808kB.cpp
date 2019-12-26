// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bitset<5000>a , b;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , k;
    cin >> n >> k;
    vector<pair<ll,ll > >temp;
    for(ll i=2;i*i<=k;i++){

        if(k%i==0){

            ll now = 0;
            while(k%i==0){

                k/=i;
                now++;
            }
            temp.push_back({i,now});
        }
    }
    if(k>1)temp.push_back({k,1});
    sort(temp.begin() , temp.end());

    ll now , ans = 1e9;
    for(int j=0;j<temp.size();j++){

        now = temp[j].first;
        ll counter = 0;
        for(ll i=now;i<=n;i*=now)counter+=n/i;
        counter/=temp[j].second;
        ans = min(ans , counter);

    }
    cout << ans << endl;
    return 0;
}
