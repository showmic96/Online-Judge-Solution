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
    for(b=0;b<26;b++) name2[b]='a'+ b;
    for(b=0;b<a;b++){
        for (c=0;c<26;c++)
        {
            if (name1[b]==name2[c]) {name2[c]=12;d+=1;}
        }
    }
    if (d%2==0) cout << "CHAT WITH HER!" << endl;
    else cout << "IGNORE HIM!" << endl;
    return 0;

}
