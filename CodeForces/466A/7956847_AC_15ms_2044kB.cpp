// In the name of Allah the Lord of the worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n , m , a , b;
    cin >> n >> m >> a >> b;
    if(m*a<=b){

        cout << n*a << endl;
    }

    else {

        if(n%m==0)cout << (n/m)*b << endl;

        else cout << min((n/m)*b + (n - (n/m)*m)*a , (n/m + 1)*b) << endl;
    }

    return 0;
}
