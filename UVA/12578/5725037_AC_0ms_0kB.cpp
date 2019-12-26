#include<iostream>
#include<stdio.h>
#include<math.h>
#define pi acos(-1)
using namespace std;

int main(void)
{
    int a,b,c;
    double d;
    cin >> a;
    for(b=0;b<a;b++){
            cin >> d;
    printf("%.2lf ", pi*(d*1/5)*(d*1/5)); printf("%.2lf\n",(d*(d*6/10))-(pi*(d*1/5)*(d*1/5)));

    }
    return 0;
}