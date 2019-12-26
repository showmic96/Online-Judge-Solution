// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ar[1234567];

int main(void)
{
    ll n;
    cin >> n;

    for(int i=0;i<n;i++)cin >> ar[i];

    sort(ar , ar+n);

    ll sum = 0 , counter = 0;

    for(int i=0;i<n;i++){

        if(sum<=ar[i]){sum+=ar[i];counter++;}
    }

    cout << counter << endl;

    return 0;
}
