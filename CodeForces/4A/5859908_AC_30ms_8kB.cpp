#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a , b ,c=0 , d=0;
    cin >> a;
    for(b=2;b<a;b+=2)
    for(c=2;c<a;c+=2)if(b+c==a){d=1;break;}
    if(d==1)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
