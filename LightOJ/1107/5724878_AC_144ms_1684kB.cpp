#include<iostream>
using namespace std;

int main(void)
{
    long long x1,y1,x2,y2,a,b,c,d,t1,t2;
    cin >> t1;
    for (d=0;d<t1;d++){
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> t2;
    long long z[t2];
    cout << "Case " << d+1 << ":" << endl;
    for(a=0;a<t2;a++){
       cin >> b >> c;
       if(b>=x1&&b<=x2&&c>=y1&&c<=y2) cout << "Yes" << endl;
       else cout << "No" << endl;
    }
    }
    return 0;
}
