#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(void)
{
    int a;
    cin >> a;

    double ox , oy ,ax, ay , bx , by ,r , theta , ad , od , dx , dy ;

    for(int i=0;i<a;i++){

        cin >> ox >> oy >> ax >> ay >> bx >> by;

        r = sqrt((ox-ax)*(ox-ax)+(oy-ay)*(oy-ay));

        dx = (ax+bx)/2;dy = (ay + by)/2;

        ad = sqrt((dx-ax)*(dx-ax)+(dy-ay)*(dy-ay));

        od = sqrt((ox-dx)*(ox-dx)+(oy-dy)*(oy-dy));

        theta = 2 * atan(ad/od);

        printf("Case %d: %.7f\n",i+1 , r*theta);
    }

    return 0;
}
