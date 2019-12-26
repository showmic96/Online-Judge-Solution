// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll k , a , b;
    cin >> k >> a >> b;
    ll ans;

    if(a>b)swap(a , b);

    if(a<0&&b<0){

        a = -a;
        b = -b;
        b--;
        ans = a/k - b/k;
    }

    else if(b>=0&&a<=0){

        ans = b/k - a/k;
        ans++;
    }

    else if(b>=0&&a>=0){

        ans = b/k - (a-1)/k;
    }

    cout << ans << endl;
    return 0;
}