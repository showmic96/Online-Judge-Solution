#include<iostream>
#include<stdio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

int main(void)
{
    long long int a , b , c=0;
    cin >> a;
    if(a>1){
        for(b=1;b<=a;b++) c+=b;
    }
    if(a<1){
        for(b=1;b>=a;b--) c+=b;
    }
    if(a==1) c=1;
    cout << c << endl;
    return 0;
}