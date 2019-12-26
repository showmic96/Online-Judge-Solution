// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lcm(ll x , ll y)
{
    return (x*y)/__gcd(x , y);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n , m;
    while(cin >> n >> m){
        vector<int>v(n);
        for(auto &x:v)cin >> x;
        for(int i=0;i<m;i++){
            ll now;
            cin >> now;
            ll ans1 = 0 , ans2 = 1e18;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=j+1;k<n;k++){
                        for(int l=k+1;l<n;l++){
                            ll t = lcm(lcm(v[i] , v[j]) , lcm(v[k] ,v[l]));
                            ans1 = max(ans1 , now/t*t);
                            if(now%t==0)ans2 = min(ans2 , now/t*t);
                            else ans2 = min(ans2 , (now/t+1)*t);
                        }
                    }
                }
            }
            cout << ans1 << " " << ans2 << endl;
        }
    }
    return 0;
}
