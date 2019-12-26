// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout.precision(6);
    cout << fixed;

    double s , a;
    string ar;

    while(cin >> s >> a >> ar){

        s+=6440;

        if(ar=="min"){

            a/=60.0;
        }

        while(a>180)a = 360.0-a;

        double arc = a*acos(-1)*s/180.0;
        a = a*acos(-1)/180.0;

        double side = sqrt(s*s+s*s-2*s*s*cos(a));

        cout << arc << " " << side << endl;
    }

    return 0;
}
