#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<math.h>
#define pi acos(-1)

using namespace std;

int main(void)
{
    long long a , b;
    double c , d , e , f;
    cin >> a;
    for(b=0;b<a;b++){
        cin >> c;
        printf("%.2lf %.2lf\n",pi*c/5*c/5, c*(c*6/10)-pi*c/5*c/5);

    }

    return 0;
}
