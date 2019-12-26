// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v , two;
bool taken[1000005];

void pre()
{
    ll lim = 1e18;
    for(ll i=2;i<=1000000;i++){

        ll now = i*i*i;
        while(now<=lim){

            v.emplace_back(now);
            if(now>lim/i)break;
            now*=i;
        }
    }

    sort(v.begin() , v.end());
    v.erase(unique(v.begin() , v.end()), v.end());

    for(int i=0;i<v.size();i++){

        ll now = (ll)sqrt(v[i]);
        if(now*now==v[i])continue;
        two.emplace_back(v[i]);
    }

    v.clear();
    v = two;
}

ll bs(ll val)
{
    ll hi = 1e9+1 , low = 1 , mid , t = 70 , ans = 0;
    while(t--){

        mid = (hi+low)/2;
        ll now = mid*mid;

        if(now<val){

            ans = mid;
            low = mid+1;
        }
        else hi = mid-1;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    pre();

    int t;
    cin >> t;
    while(t--){

        ll a , b;
        cin >> a >> b;

        ll ans = upper_bound(v.begin() , v.end(), b) - lower_bound(v.begin() , v.end() , a);
        ans+=(ll)sqrt(b)-(ll)sqrt(a-1);
        cout << ans << endl;
    }

    return 0;
}


