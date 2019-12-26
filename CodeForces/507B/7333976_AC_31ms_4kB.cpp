#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(void)
{
    double x1 ,x2 , y1 , y2 ,r;

    cin >> r >> x1 >> y1 >> x2 >> y2;
    r = r*2;

    double distance = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

    //cout << r << " " << distance << endl;

    double ans = distance/r;

    if((int)ans!=(double)ans)cout << (int)ans+1 << endl;
    else cout << (int)ans << endl;

    return 0;
}
