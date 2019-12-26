#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a , b;
    cin >> a >> b;ll ar[a];ll x=0 , y=0;
    for(ll c=0;c<a;c++){cin >> ar[c];ll k;if(ar[c]%b==0)k=ar[c]/b;else k=(ar[c]/b)+1;if(k>=x){x=k;y=c;}}
    cout << y+1 << endl;
    return 0;
}
