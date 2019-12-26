// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans = 0;
vector<ll>v;
int n;

void f(ll i , ll now)
{
    if(i==n){
        ans+=now;
        return ;
    }
    f(i+1 , now);
    f(i+1 , now|v[i]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        v.push_back(in);
    }
    f(0 , 0);
    cout << ans << endl;
    return 0;
}
