// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar;

int main(void)
{

    getline(cin , ar);

    stringstream ss(ar);
    int a , b , c;
    char x;

    ss >> a;
    ss >> x;
    ss >> b;
    ss >> x;
    ss >> c;

    if(a+b==c)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
