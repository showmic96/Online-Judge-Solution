#include<bits/stdc++.h>
using namespace std;

int main(void)

{
    char a[35];
    while(cin >> a){
        int b;
        for(b=0;b<strlen(a);b++){
            if(a[b]=='A'||a[b]=='B'||a[b]=='C')a[b]='2';
            if(a[b]=='D'||a[b]=='E'||a[b]=='F')a[b]='3';
            if(a[b]=='G'||a[b]=='H'||a[b]=='I')a[b]='4';
            if(a[b]=='J'||a[b]=='K'||a[b]=='L')a[b]='5';
            if(a[b]=='M'||a[b]=='N'||a[b]=='O')a[b]='6';
            if(a[b]=='P'||a[b]=='Q'||a[b]=='R'||a[b]=='S')a[b]='7';
            if(a[b]=='T'||a[b]=='U'||a[b]=='V')a[b]='8';
            if(a[b]=='W'||a[b]=='X'||a[b]=='Y'||a[b]=='Z')a[b]='9';
        }
        cout << a << endl;
        memset(a,'\0',sizeof(a));
    }
    return 0;
}
