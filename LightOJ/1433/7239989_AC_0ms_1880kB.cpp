#include<bits/stdc++.h>
using namespace std;

#define PI acos(-1)

int main(void)
{
    int a , b;
    cin >> a;

    double ox , oy , ax , ay , bx , by , cx , cy , oc , ac , thita;

    for(int i=0;i<a;i++){

        cin >> ox >> oy >> ax >> ay >> bx >> by;
        cx = (ax+bx)/2;
        cy = (ay+by)/2;

        oc = sqrt((ox-cx)*(ox-cx)+(oy-cy)*(oy-cy));
        ac = sqrt((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy));
        thita = atan(ac/oc);
        //cout << ax-cx << " " << ay-cy << endl
        //cout << ac << " " << oc << " " << cx << " " << cy << endl;

        thita*=2;
        double r = sqrt((ax-ox)*(ax-ox)+(ay-oy)*(ay-oy));
        printf("Case %d: %.7lf\n",i+1,r*thita);
    }

    return 0;
}
