// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n , k;
    cin >> n >> k;

    set<ll>ans;
    set<ll>:: iterator it;
    ans.insert(1);
    ans.insert(n);
    if(n%2==0){

        ans.insert(2);
        ans.insert(n/2);
    }

    for(ll i=2;i*i<=n;i++){

        if(n%i==0){

            ans.insert(i);
            ans.insert(n/i);
        }
    }

    if(ans.size()<k)cout << -1 << endl;
    else {

        it = ans.begin();
        advance(it , k-1);
        cout << *it << endl;
    }

    return 0;
}
