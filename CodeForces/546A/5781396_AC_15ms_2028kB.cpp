#include<iostream>
using namespace std;

int main(void)
{
    long long a , b , c , d=0,e ,f;
    cin >> a >> b >> c;
    d=a;
    for(e=2;e<c+1;e++){
        d+=(a*e);

    }
    if(d>b)cout << d-b << endl;
    else cout << 0 << endl ;
    return 0;
}
