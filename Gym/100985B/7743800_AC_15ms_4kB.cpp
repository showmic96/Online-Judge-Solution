// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(void)
{
    ll n , in;
    cin >> n;

    for(int i=0;i<n;i++)cin >> in;

    cout << floor(log2(n))+1 << endl;

    return 0;
}
