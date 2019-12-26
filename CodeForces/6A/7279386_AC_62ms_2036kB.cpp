#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int a[4];

    cin >> a[0] >> a[1] >> a[2] >> a[3];

    sort(a , a+4);

    if(a[0]+a[1]>a[2]||a[1]+a[2]>a[3])cout <<"TRIANGLE" << endl;
    else if(a[0]+a[1]==a[2]||a[1]+a[2]==a[3])cout << "SEGMENT"  << endl;
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}
