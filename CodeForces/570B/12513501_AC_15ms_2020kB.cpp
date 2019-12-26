// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n ,m;
    cin >> n >> m;

    int t = n-m;

    if(n==1)cout << 1 << endl;
    else if(t>=m)cout << m+1 << endl;
    else cout << m-1 << endl;

    return 0;
}
