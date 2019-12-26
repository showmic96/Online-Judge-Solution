#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main (void)
{
    char ar[15];
    ll b;
    cin >> b;
    for(ll a=0;a<b;a++){cin >> ar;
    if(strlen(ar)==5)cout << 3 << endl;
    else if(ar[0]=='o'&&ar[1]=='n'||ar[0]=='o'&&ar[2]=='e'||ar[1]=='n'&&ar[2]=='e')cout << 1 << endl;
    else cout << 2 << endl;
    }
    return 0;

}
