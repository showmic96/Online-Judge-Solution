// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    ll lim = (double)ceil(sqrt(n));


    for(int i=1;i<=lim;i++){

        for(int j=1;j<=lim;j++){

            if(i*j>=n){

                cout << 2*i+2*j << endl;

                return 0;
            }
        }
    }

    return 0;
}
