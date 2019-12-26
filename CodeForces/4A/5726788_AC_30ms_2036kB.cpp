#include<iostream>
#include<stdio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define pi 2*acos(0.0)
using namespace std;

int main(void)
{
    int a , b , c , d=0 ;
    cin >> a;
    for(b=2;b<100;b=b+2)
    for(c=2;c<100;c=c+2)
    if(b+c==a){d=1;break;}
    if(d==1) cout << "YES" << endl;
    else cout << "NO" <<endl;


    return 0;
}
