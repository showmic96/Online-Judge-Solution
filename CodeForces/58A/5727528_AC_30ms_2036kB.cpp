#include<iostream>
#include<stdio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

using namespace std;

int main(void)
{
    int a , b ,d , c1=0,c2=0,c3=0,c4=0,c5=0 ;
    char x[110];
    cin >> x ;
    d=strlen(x);
    for(b=0;b<d;b++)
    if(x[b]=='h'){c1+=1;b++;break;}
    for(;b<d;b++)
    if(x[b]=='e'){c1+=1;b++;break;}
    for(;b<d;b++)
    if(x[b]=='l'){c1+=1;b++;break;}
    for(;b<d;b++)
    if(x[b]=='l'){c1+=1;b++;break;}
    for(;b<d;b++)
    if(x[b]=='o'){c1+=1;b++;break;}

    if(c1==5) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}