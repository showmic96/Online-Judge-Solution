// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll phi(ll n)
{
    ll ret = n;
    for(int i=2;i*i<=n;i++){

        if(n%i==0){

            while(n%i==0){

                n/=i;
            }

            ret-=ret/i;
        }
    }
    if(n>1)ret-=ret/n;
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        ll n;
        cin >> n;

        cout << phi(n)*(n-1) << endl;
    }

    return 0;
}
