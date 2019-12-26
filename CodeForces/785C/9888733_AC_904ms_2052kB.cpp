// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n , m , cnt = 0;
    cin >> n >> m;

    if(m>=n){

        cout << n << endl;
        return 0;
    }

    n-=m;

    while(n>0){

        cnt++;
        n-=cnt;
    }

    cout << m+cnt << endl;

    return 0;
}
