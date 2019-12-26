#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main (void)
{
    ll ar[10];
    for(ll a=0;a<10;a++)cin >> ar[a];
    sort(ar,ar+10);
    cout << ar[9] << endl << ar[8] << endl << ar[7] << endl;
    return 0;

}

