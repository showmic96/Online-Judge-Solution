// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    double n , a;
    cin >> n >> a;
    double r = a/(2*sin(acos(-1)/n));
    double area = acos(-1)*r*r;
    cout << setprecision(14) << fixed << area << endl;
    return 0;
}
