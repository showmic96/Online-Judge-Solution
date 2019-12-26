// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5+100;

ll ar[MAX];

int main(void)
{
    ll a , hi = -100,ans = 0;
    cin >> a;
    bool check = true;

    for(int i=0;i<a;i++){
        cin >> ar[i];
        if(ar[i]>hi){hi = ar[i];ans = i;}
        else if(ar[i]==hi)check=false;
    }

    if(check==false)cout << -1 << endl;
    else cout << ans + 1 << endl;
    return 0;
}
