// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v;
ll n;

bool possible(ll x)
{
    int now = 0;
    for(int i=x;i<n;i++){

        if(v[i]>=2LL*v[now])now++;
        if(now>=x)break;
    }

    if(now>=x)return true;
    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        v.push_back(in);
    }

    sort(v.begin() , v.end());

    ll hi = n , mid , low = 0 , ans = 0 , t = 200;

    while(t--){

        mid = (hi+low)/2;

        if(possible(mid)==true){

            ans = mid;
            low = mid+1;
        }
        else hi = mid-1;
    }

    cout << n - ans << endl;

    return 0;
}
