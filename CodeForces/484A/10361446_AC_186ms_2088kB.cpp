// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> bin(ll x)
{
    vector<ll>v;

    while(x!=0){

        v.push_back(x%2);
        x/=2;

    }

    while(v.size()!=64)v.push_back(0);

    reverse(v.begin() , v.end());

    return v;
}

ll dec(vector<ll>v)
{
    ll ans = v[0];

    for(int i=1;i<v.size();i++){

        ans*=2;
        ans+=v[i];
    }

    return ans;
}

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        ll a , b;
        cin >> a >> b;

        vector<ll>v;

        v = bin(a);
        ll ans = a;

        int si = v.size();

        for(int i=si-1;i>=0;i--){

            if(v[i]==0){

                v[i] = 1;

                ll temp = dec(v);

                if(temp<=b){

                    ans = temp;
                }

                else{

                    break;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
