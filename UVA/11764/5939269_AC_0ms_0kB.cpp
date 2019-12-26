#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a;
    cin >> a;
    for(ll b=0;b<a;b++){
        ll c , d , e=0,f=0,g=0;
        cin >> c;cin >> e;
        for(ll k=0;k<c-1;k++){cin >> d;if(d>e)f++;if(d<e)g++;e=d;}
        printf("Case %lld: ",b+1);
        cout << f << " " << g << endl;
    }
    return 0;
}
