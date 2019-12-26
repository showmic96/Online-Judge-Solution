#include<iostream>
#include<stdio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

int main(void)
{
    int b,c,d;
    cin >> c;
    for(b=0;b<c;b++){
    char a[10];
    cin >> a;
    d=0;
    if(strlen(a)==3){
    if(strlen(a)==3&&(strchr(a,'o')&&strchr(a,'n'))||(strchr(a,'e')&&strchr(a,'n'))||(strchr(a,'e')&&(strchr(a,'o')))) cout << 1 << endl;
    else  cout << 2 << endl;
    }
    else cout << 3 << endl;

    }
    return 0;
}
