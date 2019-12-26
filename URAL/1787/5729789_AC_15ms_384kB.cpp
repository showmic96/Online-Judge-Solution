#include<iostream>
#include<stdio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

int main(void)
{
    long long a , b , c , d , e , f=0 , g , h , i , j;
    cin >> a >> b;
    f=0;

    for(c=0;c<b;c++){
    cin >> e;
    e+=f;
    f=0;
    if(e>=a) f+=(e-a);
    if(e<a) f+=0;
    }

    cout << f << endl;


    return 0;
}
