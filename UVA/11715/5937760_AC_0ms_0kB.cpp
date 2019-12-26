#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    double  b , c , d;ll e=0,a;
    while(cin >> a){
        if(a==0)break;
        cin >> b >> c >> d;

        printf("Case %lld: ",e+1);
        if(a==1) printf("%.3lf %.3lf", abs((c*c-b*b)/(2*(c-b)/d)) , (c-b)/d );
        if(a==2) printf("%.3lf %.3lf",abs((c*c-b*b)/(2*d)) ,(c-b)/d);
        if(a==3) printf("%.3lf %.3lf",abs(sqrt(b*b+2*c*d)),abs((sqrt(b*b+2*c*d)-b)/c));
        if(a==4) printf("%.3lf %.3lf", abs(sqrt(b*b-2*c*d)),abs((sqrt(b*b-2*c*d)-b)/c));
        cout << endl;
        e++;
    }
    return 0;
}
