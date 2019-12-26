#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    sort(a , a+3);

    int var1 = a[0] - a[1] - a[2];
    int var2 = a[0] - a[1] * a[2];

    cout << min(var1 , var2) << endl;

    return 0;
}
