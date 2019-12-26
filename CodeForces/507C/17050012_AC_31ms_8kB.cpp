// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans = 0 , now = 0;

void f(ll n , ll h , ll tot , ll dir)
{
    if(n==1&&h==0){

        ans = tot;
        return ;
    }

    ll l = (1LL<<(h-1));
    ll r = l;

    if(dir==0){

        if(n>l)f(n-l , h-1 , tot+(1LL<<h) , 0);
        else f(n , h-1 , tot+1 , 1);
    }
    else{

        if(n>l)f(n-l , h-1 , tot+1 , 0);
        else f(n , h-1 , tot+(1LL<<h) , 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll h , n;
    cin >> h >> n;

    f(n , h , 0 , 0);

    cout << ans << endl;

    return 0;
}
