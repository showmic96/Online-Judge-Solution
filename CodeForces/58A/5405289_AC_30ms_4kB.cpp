#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;

int main(void)
{
    char name1[1000] , name2[27];
    gets(name1);
    int a ,b , c ,d=0;
    a=strlen(name1);
    for(b=0;b<a;b++){
        if (name1[b]=='h'){d+=1;break;}
    }
    for(++b;b<a;b++){
        if (name1[b]=='e'){d+=1;break;}
    }
    for(++b;b<a;b++){
        if (name1[b]=='l'){d+=1;break;}
    }
    for(++b;b<a;b++){
        if (name1[b]=='l'){d+=1;break;}
    }
    for(++b;b<a;b++){
        if (name1[b]=='o'){d+=1;break;}
    }
    if(d==5) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;

}