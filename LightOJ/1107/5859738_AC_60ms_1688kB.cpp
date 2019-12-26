#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main (void)
{
    ll a , b , c ,d , e ,f , g , h , i , j;
    cin >> a;
    for(b=0;b<a;b++){
        printf("Case %lld:\n",b+1);
        cin >> c >> d >> e >> f;
        cin >> g;
        for(h=0;h<g;h++){
            cin >> i >> j;
            if(i>=c&&i<=e&&j>=d&&j<=f)cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
