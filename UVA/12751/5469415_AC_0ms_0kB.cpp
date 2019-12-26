#include<iostream>

using namespace std;

int main(void)
{
    int a , b , c, d ,e ,f,g=0,i,j,k,z;
    cin >> a;
    for(b=0;b<a;b++){
            g=0;
        //char ac;
        e=0;
        cin >> i >> j >>k;
        for(c=1;c<=i;c++)
            e+=c;
        for(d=k,z=0;z<j;d++,z++)
            g+=d;


        cout <<"Case " << b+1 <<": "<< e-g << endl;

           }
    return 0;
}