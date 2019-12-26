// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    double r , x1, x2 , y1 , y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;

    double dis = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

    //cout << dis << endl;

    cout << (int)ceil(dis/(2*r)) << endl;

    return 0;
}
