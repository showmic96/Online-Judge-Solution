// In the name of Allah the most Merciful .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a , b;
    cin >> a >> b;

    if(b==0&&a==1)cout << 1 << endl;
    else if(b<a/2||a==1)cout << -1 << endl;
    else{

        ll ans = b - (a/2) + 1;

        cout << ans*2 << " " << ans;
        ll d = 300;
        for(int i=0;i<a-2;i++){

            if(i+d==ans||i+d==2*ans)d+=2;
            cout <<" " <<  (ll)(i+d) ;
        }
        cout << endl;
    }
    return 0;
}
