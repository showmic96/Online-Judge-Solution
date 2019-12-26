// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    cin >> n;
    ll s1 = 0 , s2 = 0;
    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        s1+=in;
    }
    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        s2+=in;
    }

    if(s1>=s2)cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
