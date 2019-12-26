#include<iostream>

using namespace std;

int main(void)
{
    int a , b , c , d , e , f , g=0 , h=0;
    cin >> a;
    for(b=0;b<a;b++){
            g=0;h=0;
        cin >> c >> d;
        int array1[c],array2[c];
        for(e=0;e<c;e++) {cin >> array1[e];h+=array1[e];}
        for(e=0;e<c;e++) cin >> array2[e];
        for(e=0;e<c;e++) if(array2[e]<array1[e])g=1;
        if(h>d||g==1) cout <<"Case "<<b+1<<": No"<<endl;
        else cout <<"Case "<<b+1<<": Yes"<<endl;
    }

    return 0;
}