#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a , b , c;

    while(cin >> a >> b >>  c){

        if(!a&&!b&&!c)break;

        if(c-b==b-a)cout << "AP " << c+b-a << endl;
        else cout << "GP " << b/a*c << endl;
    }

    return 0;
}
