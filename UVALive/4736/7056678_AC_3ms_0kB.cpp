#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a;

    int counter = 0;

    while(cin >> a){

        if(!a)break;

        cout << ++counter << ". ";

        if(a%2==1)cout << "odd ";
        else cout << "even ";

        cout << a/2 << endl;
    }

    return 0;
}
