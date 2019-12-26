#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a , b;
    cin >> a >> b;
    ll ar[a];
    for(ll c=0;c<a;c++)ar[c]=0;
    for(ll c=0;c<b;c++){
        ll j=0,k=0;
        for(ll d=0;d<a;d++){
            ll in;
            cin >> in;
            if(in>j){j=in;k=d;}

        }
        ar[k]++;
    }
    ll j=0,k=0;
    for(ll c=0;c<a;c++){
        if(ar[c]>j){j=ar[c];k=c;}
    }
    cout << k+1 << endl;

    return 0;

}
