#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    long long a;
    cin >> a;
    int ar[a];
    for(long long b=0;b<a;b++)cin >> ar[b];
    sort(ar,ar+a);
    if(ar[0]==1){cout << -1 << endl;}
    else cout << 1 << endl;
    return 0;
}
