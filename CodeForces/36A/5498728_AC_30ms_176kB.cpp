#include<iostream>
#include<string.h>
#include<string>
//#include<stdint-gcc.h>
#include<stdio.h>
//#include freopen( "input.txt" , "r" , stdin )
//#include freopen( "output.txt" , 'w" , stdout ) ;
using namespace std;

int main(void)
{
    freopen( "input.txt" , "r" , stdin );
    freopen( "output.txt" , "w" , stdout ) ;
    int a , c , e=0 , f , g=1;

    cin >> a;
    char b[105];int d[105];
    cin >> b;
    for(c=0;c<a;c++)
        if(b[c]=='1'){d[e]=c;e++;}
    for(c=0;c<e-2;c++)
        if((d[c+1]-d[c])!=(d[c+2]-d[c+1])) g=0;
    if(g==1)cout << "YES" << endl;
    if(g==0)cout << "NO" << endl;


    return 0;
}