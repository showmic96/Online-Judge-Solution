#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a , b , c;

    cin >> a >> b >> c;

    if(abs(a)+abs(b)>c)cout << "No" << endl;

    else{

        ll rem = c-(abs(a)+abs(b));


        if(rem%2==0)cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
