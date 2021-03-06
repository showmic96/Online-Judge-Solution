// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll>v;
ll n , m , k;

bool possible(ll mid)
{
    ll counter = m-1 , now = k;
    for(int i=0;i<mid;i++){

        if(v[i]>now){

            if(v[i]>k)return false;
            now = k;
            now-=v[i];
            counter--;
            if(counter<0)return false;
        }
        else{
            now-=v[i];
        }
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        v.push_back(in);
    }

    reverse(v.begin() , v.end());

    ll hi = n , low = 0 , ans = 0 , mid , t = 100;
    while(t--){

        mid = (hi+low)/2;
        if(possible(mid)==true){

            ans = mid;
            low = mid+1;
        }
        else hi = mid-1;
    }
    cout << ans << endl;

    return 0;
}
