#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

bool ifPrime(long long x)
{
    long long a = sqrt((double)x), b;
    for(b=3;b<=a;b+=2)
        if(x%b==0)return false;
    return true;
}

int main(void)
{
    long long a , b , c, d , e;
    cin >> a;
    for(b=0;b<a;b++){
        if(b>=1)cout << endl;
        cin >> c >> d ;
        if(d<c) {e=d;d=c;c=e;}
        if(c==1||c==2){cout << 2 << endl;if(c==2)c++;if(c==1)c+=2;}
        if(c%2==0)c++;
        for(;c<=d;c+=2)if(ifPrime(c)==true)cout << c << endl;
    }
    return 0;
}
