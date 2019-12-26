// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll _lcm(ll a , ll b)
{
    return a/__gcd(a , b)*b;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        vector<ll>v;
        cin >> n;

        for(int i=0;i<n;i++){

            int in;
            cin >> in;
            v.push_back(in);
        }

        int counter = 0;

        for(int i=0;i<n;i++){

            ll sum = 0;
            ll lcm = 1;

            for(int j=i;j<n;j++){

                sum+=v[j];
                lcm = _lcm(lcm , v[j]);

                if(lcm>2e13)break;

                if(sum%lcm==0)counter++;
            }
        }

        cout << counter << endl;
    }
    return 0;
}
