#include<stdio.h>
#include<iostream>
#include<string.h>
typedef long long ll;

using namespace std;

int main(void)
{
    char ar[15];int a=1;
    while(gets(ar)){
         if(ar[0]=='#')break;
         printf("Case %d: ",a);a++;
         if(strcmp(ar,"ZDRAVSTVUJTE")==0)cout << "RUSSIAN" << endl;
         else if(strcmp(ar,"CIAO")==0)cout << "ITALIAN" << endl;
         else if(strcmp(ar,"BONJOUR")==0)cout << "FRENCH" << endl;
         else if(strcmp(ar,"HALLO")==0)cout << "GERMAN" << endl;
         else if(strcmp(ar,"HOLA")==0)cout << "SPANISH" << endl;
         else if(strcmp(ar,"HELLO")==0)cout << "ENGLISH" << endl;
         else cout << "UNKNOWN" << endl;
    }

    return 0;
}