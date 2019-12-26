// In the name of Allah the Lord of the worlds .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int a , b;
    cin >> a;

    ll ans , ar[1010];

    while(a--){

        ans = 0;

        cin >> b;

        for(int i=0;i<b;i++)cin >> ar[i];

        sort(ar , ar+b);

        for(int i=1;i<b;i++)ans+=ar[i] - ar[0];

        cout << ans << endl;
    }
}
