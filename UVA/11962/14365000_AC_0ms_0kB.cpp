// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll p(ll x , ll t)
{
    ll now = 1;
    for(int i=0;i<t;i++)now*=x;
    return now;
}

ll f(string ar)
{
    ll ans = 0;
    for(int i=0;i<ar.size();i++){

        if(ar[i]=='C'){

            ans+=1LL*p(4 , ar.size()-i-1);
        }
        else if(ar[i]=='G'){

            ans+=2LL*p(4 , ar.size()-i-1);

        }
        else if(ar[i]=='T'){

            ans+=3LL*p(4 , ar.size()-i-1);
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t , c = 0;
    cin >> t;
    while(t--){

        string ar;
        cin >> ar;

        cout << "Case " << ++c << ": (" << ar.size() << ":" << f(ar) << ")" << endl;
    }
    return 0;
}
