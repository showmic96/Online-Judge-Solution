// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio();
    cin.tie(0);cout.tie(0);

    int n , m;
    cin >> n >> m;
    m = min(m-1 , n-m);
    cout << 3*n+m << endl;

    return 0;
}
