#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int a;

    cin >> a;

    int counter;

    ll ans;

    while(a--){

        cin >> counter >> ans;

        cout << counter << " " << ans*(ans+1)/2 << " " << ans*ans << " " << ans*(ans+1) << endl;
    }

    return 0;
}
