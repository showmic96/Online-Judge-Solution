// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        ll n , w;
        cin >> n >> w;

        ll ar[n];

        for(int i=0;i<n;i++)cin >> ar[i];

        sort(ar , ar+n);

        int counter = 0;

        for(int i=0;i<n;i++){

            if(w-ar[i]>=0){

                w-=ar[i];
                counter++;
            }
        }

        cout << counter << endl;
    }

    return 0;
}
