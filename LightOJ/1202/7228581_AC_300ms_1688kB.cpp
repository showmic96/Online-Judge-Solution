#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 , MAX = 100010;
typedef long long ll;
typedef unsigned long long LL;



int main(void)
{
    int a , in;

    //cout << 0%2 << endl;
    cin >> a;
    ll r1 , r2 , c1 , c2;

    for(int i=0;i<a;i++){

        cin >> r1 >> c1 >> r2 >> c2;

        printf("Case %d: ",i+1);
        if(r1==r2&&c1==c2)cout << 0 << endl;
        else if(abs(r1-c1)%2==0&&abs(r2-c2)%2==1||(abs(r1-c1)%2==1&&abs(r2-c2)%2==0))cout << "impossible" << endl;
        else if(abs(r1-r2)==abs(c1-c2))cout << 1 << endl;
        //else if(r1==c1&&r2==c2)cout << 1 << endl;
        else cout << 2 << endl;

        //if(r1-r2==c1-c2)

    }

    return 0;
}
