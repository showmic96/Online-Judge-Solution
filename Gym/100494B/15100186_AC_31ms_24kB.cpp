// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll two[44];
    two[0] = 1;
    for(int i=1;i<44;i++)two[i] = two[i-1]*2LL;
    
    ll n , m;
    while(cin >> n >> m)
    
    if((1LL<<(m+1))>n)cout << "yes" << endl;
    else cout << "no" << endl;
    
    return 0;
}