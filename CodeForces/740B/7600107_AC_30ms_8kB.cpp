#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void)
{
    ll n , m , counter =0 , sum = 0;

    cin >> m >> n;

    ll ar[m];

    for(int i=0;i<m;i++)cin >> ar[i];

    for(int i=0;i<n;i++){

        ll a , b;

        sum = 0;

        cin >> a >> b;

        for(ll j=a-1;j<b;j++){

            sum+=ar[j];
        }

        if(sum>0)counter+=sum;
    }

    cout << counter << endl;

    return 0;

}
