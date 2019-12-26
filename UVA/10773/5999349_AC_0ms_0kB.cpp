#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;
    cin >> a;
    for(int b=0;b<a;b++){
        double u , v , d;

        cin >> d >> v >> u;
        if(v==0||u==0||u<=v){printf("Case %d: can't determine\n",b+1);continue;}
        double t1=1.0*d/sqrt(u*u-v*v)*1.0;
        double t2=1.0*d/u;
       // cout << t1 << endl << t2 << endl;
        printf("Case %d: %.3f\n",b+1,abs(t1-t2));
    }
    return 0;
}
