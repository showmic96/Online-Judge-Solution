// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ar[33] , two[33];

int get(ll x)
{
    int counter = 0;
    while(x>1){

        x/=2;
        counter++;
    }

    return counter;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    two[0] = 1;
    for(ll i=1;i<=32;i++)two[i] = two[i-1]*2;

    int n , m;
    cin >> n >> m;
    memset(ar , 0 , sizeof(ar));

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;

        ar[get(in)]++;
    }

    while(m--){

        ll in;
        cin >> in;

        ll counter = 0;

        for(int i=32;i>=0;i--){

            ll temp = in/two[i];
            temp = min(temp , ar[i]);

            counter+=temp;
            in-=two[i]*temp;
        }

        if(!in)cout << counter << endl;
        else cout << -1 << endl;
    }

    return 0;
}
