// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , k;
vector<ll>v;

bool possible(ll mid)
{
    ll tk = k;
    for(int i=n/2;i<n;i++){
        ll temp = 0;
        if(v[i]<mid)temp+=mid-v[i];
        tk-=temp;
        if(tk<0)return false;
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for(int i=0;i<n;i++){
        ll in;
        cin >> in;
        v.push_back(in);
    }
    sort(v.begin() , v.end());
    ll hi = 1e15 , low = 0 , mid , ans = -1 ,t = 70;
    while(t--){
        mid = (hi+low)/2;
        if(possible(mid)==true){
            ans = mid;
            low = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    cout << ans << endl;

    return 0;
}
