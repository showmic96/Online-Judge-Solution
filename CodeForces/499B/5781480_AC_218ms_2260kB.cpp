#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int main(void)
{
    long long a , b , c , d ;
    cin >> a >> b;
    char string1[b+1][11] , string2[b+1][11] , string3[a+1][11];
    for(c=0;c<b;c++){
        cin >> string1[c] >> string2[c];
    }
    for(c=0;c<a;c++) cin >> string3[c];
    for(c=0;c<a;c++)
        for(d=0;d<b;d++){
        if(stricmp(string3[c],string1[d])==0||stricmp(string3[c],string2[d])==0){if(strlen(string1[d])>strlen(string2[d])) cout << string2[d] << " ";
                                                                                     else cout << string1[d]<<" ";}
    }
    cout << endl;
    return 0;
}