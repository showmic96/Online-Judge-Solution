// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

string f(string ar)
{
    int si = ar.size();

    if(si%2==1)return ar;

    string t1 = f(ar.substr(0 , si/2));
    string t2 = f(ar.substr(si/2 , si));

    if(t1<t2)return t1+t2;
    else return t2+t1;
}

int main(void)
{
    string ar , br;
    cin >> ar >> br;

    if(f(ar)==f(br))cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
