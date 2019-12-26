// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , k , ans = 0;
    cin >> n >> k;
    while(n){
        ans++;
        n/=k;
    }
    cout << ans << endl;
    return 0;
}
