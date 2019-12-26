#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a ;
    cin >> a;
    for(ll b=0;b<a;b++){
        ll c ;
        cin >> c;ll ar[c];
        for(ll d=0;d<c;d++)cin >> ar[d];
        sort(ar,ar+c);
        printf("Case %lld: ",b+1);
        cout << ar[c/2] << endl;
    }
    return 0;

}
