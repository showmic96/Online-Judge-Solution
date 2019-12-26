#include<iostream>
#include<stdio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define pi 2*acos(0.0)
using namespace std;

int main(void)
{
    int a,d,e,f;
    double  b , c=0;
    cin >> a;
    for(d=0;d<a;d++){
        cin >> b;
        cout << "Case " <<d+1 <<": ";printf("%.2lf\n",(4*b*b)-(pi*b*b));
    }

    return 0;
}