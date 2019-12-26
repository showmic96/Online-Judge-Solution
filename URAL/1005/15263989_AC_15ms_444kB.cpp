// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll sum = 0;
vector<ll>v;

ll f(int i , ll val)
{
    if(val>sum/2)return 1e18;
    if(i==n){

        return abs(sum-val-val);
    }

    ll value = 1e18;
    value = min(value , f(i+1 , val+v[i]));
    value = min(value , f(i+1 , val));

    return value;
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
        sum+=in;
    }

    cout << f(0 , 0) << endl;

    return 0;
}
