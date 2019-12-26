#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a;
    cin >> a;
    ll ar[a];
    for(ll b=0;b<a;b++)cin >> ar[b];
    sort(ar,ar+a);
    if(ar[0]==1)cout << -1 << endl;
    else cout << 1 << endl;
    return 0;

}
