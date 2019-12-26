#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll ar[10];

    for(int i=0;i<10;i++)cin >> ar[i];

    sort(ar,ar+10);

    cout << ar[9] << endl;
    cout << ar[8] << endl;
    cout << ar[7] << endl;

    return 0;

}
