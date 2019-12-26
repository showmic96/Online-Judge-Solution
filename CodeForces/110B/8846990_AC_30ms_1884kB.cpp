// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)cout << (char)('a' + i%4);
    cout << endl;
    return 0;
}
