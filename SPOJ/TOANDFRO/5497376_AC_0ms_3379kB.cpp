#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int main(void)
{
    int a , k=0 , b , c ,d ;
    char array1[205];
    for(;;)
    {
        cin >> a ;
            k=0;
            if(a==0) break;
            cin >> array1;

    b=strlen(array1);
    b=b/a;
    char array2[b+1][a+1];

    for(c=0;c<b;c=c+2){
        for(d=0;d<a;d++){array2[c][d]=array1[k];k++;}
        for(d=a-1;d>=0;d--){array2[c+1][d]=array1[k];k++;}
    }
    //for(c=1;c<b;c=c+2){
       // for(d=0;c<a;d++){array2[c][d]=array1[k];k++;}
        //for(d=a-1;d>=0;d--){array2[c][d]=array1[k];k++;}
    //}
    //cout << "alu";
    for(c=0;c<a;c++)
        for(d=0;d<b;d++)
        cout << array2[d][c] ;
        cout << endl;
    }
    return 0;
}
